#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fill_random(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

int main(void) {
    srand(time(NULL));
    
    int n = 1000; 
    int *original = malloc(n * sizeof(int));
    int *arr = malloc(n * sizeof(int));
    
    if (!original || !arr) {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }
    
    fill_random(original, n);
    
    
    
    // SELECTION SORT
    copy_array(original, arr, n);
    clock_t start = clock();
    selection_sort(arr, n);
    double time_selection = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %.4f sec - Trié: %s\n", time_selection, 
           is_sorted_nondecreasing(arr, n) ? "OUI" : "NON");
    
    //  INSERTION SORT
    copy_array(original, arr, n);
    start = clock();
    insertion_sort(arr, n);
    double time_insertion = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %.4f sec - Trié: %s\n", time_insertion,
           is_sorted_nondecreasing(arr, n) ? "OUI" : "NON");
    
    //  BUBBLE SORT
    copy_array(original, arr, n);
    start = clock();
    bubble_sort(arr, n);
    double time_bubble = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort:    %.4f sec - Trié: %s\n", time_bubble,
           is_sorted_nondecreasing(arr, n) ? "OUI" : "NON");
    
    // MERGE SORT
    copy_array(original, arr, n);
    start = clock();
    merge_sort(arr, n);
    double time_merge = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort:     %.4f sec - Trié: %s\n", time_merge,
           is_sorted_nondecreasing(arr, n) ? "OUI" : "NON");
    
    //  QUICK SORT
    copy_array(original, arr, n);
    start = clock();
    quick_sort(arr, n);
    double time_quick = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort:     %.4f sec - Trié: %s\n", time_quick,
           is_sorted_nondecreasing(arr, n) ? "OUI" : "NON");
    
    free(original);
    free(arr);
    return 0;
}