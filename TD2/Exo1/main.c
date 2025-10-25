#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    
    srand(time(NULL));
    
    int n = 1000000;
    int *arr = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    
    
    int target = rand() % n;
    
    printf("Taille: %d, Cible: %d\n\n", n, target);
    
   
    clock_t start = clock();
    int idx1 = linear_search(arr, n, target);
    double t1 = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Linear:  %.6f sec\n", t1);
    
   
    start = clock();
    int idx2 = jump_search(arr, n, target);
    double t2 = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Jump:    %.6f sec\n", t2);
    
    
    start = clock();
    int idx3 = binary_search(arr, n, target);
    double t3 = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Binary:  %.6f sec\n", t3);
    
    printf("\nIndex trouvés: %d, %d, %d\n", idx1, idx2, idx3);
    
    free(arr);
    return 0;
}