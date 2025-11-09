#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;


int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // par défaut on met feuille = hauteur 1
    return node;
}

// Rotations AVL
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // we update here hueghts 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

   
    y->left = x;
    x->right = T2;

   
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

   
    return y;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


// Insertion in AVL

Node* insert(Node* node, int key) {
    // Binary Search treeee
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

   
    node->height = 1 + max(height(node->left), height(node->right));

   
    int balance = getBalance(node);

    // exceptions
    // left-left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // right-right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // left-righht
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // rigght-left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

   
    return node;
}


// BST in avl
int search(Node* root, int key) {
    if (root == NULL)
        return 0; 
    if (key == root->key)
        return 1; 
    else if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}
int main() {
    struct Node *root = NULL;
    FILE *fptr;
    int n_insert, n_search, key;

    fptr = fopen("test07.txt", "r");
    if (fptr == NULL) {
        printf("Erreur : impossible d’ouvrir test1.txt\n");
        return 1;
    }

    
    fscanf(fptr, "%d", &n_insert);

   
    for (int i = 0; i < n_insert; i++) {
        fscanf(fptr, "%d", &key);
        root = insert(root, key);
    }

   
    fscanf(fptr, "%d", &n_search);

   
    for (int i = 0; i < n_search; i++) {
        fscanf(fptr, "%d", &key);
        if (search(root, key))
            printf("true\n");
        else
            printf("false\n");
    }

    fclose(fptr);
    return 0;
}