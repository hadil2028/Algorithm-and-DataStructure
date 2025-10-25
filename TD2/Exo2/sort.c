#include <stdlib.h>
#include "sort.h"
#include "utils.h"

// SELECTION SORT
void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap_int(&arr[i], &arr[min_idx]);
    }
}

// INSERTION SORT
void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// BUBBLE SORT
void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// MERGE SORT - funtion de fusion
void merge(int *arr, int *tmp, int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    
    while (i <= m) {
        tmp[k++] = arr[i++];
    }
    
    while (j <= r) {
        tmp[k++] = arr[j++];
    }
    
    for (i = l; i <= r; i++) {
        arr[i] = tmp[i];
    }
}

// MERGE SORT - partie récursive
void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort_rec(arr, tmp, l, m);
        mergesort_rec(arr, tmp, m + 1, r);
        merge(arr, tmp, l, m, r);
    }
}

// MERGE SORT - funciton principale
void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1) return;
    
    int *tmp = (int *)malloc(n * sizeof(int));
    if (!tmp) return;
    
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

// QUICK SORT - partitioon
int partition(int *arr, int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i + 1], &arr[r]);
    return i + 1;
}

// QUICK SORT - part récursive
void quick_sort_rec(int *arr, int l, int r)
{
    if (l < r) {
        int pi = partition(arr, l, r);
        quick_sort_rec(arr, l, pi - 1);
        quick_sort_rec(arr, pi + 1, r);
    }
}

// QUICK SORT - funciton principale
void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1) return;
    quick_sort_rec(arr, 0, n - 1);
}