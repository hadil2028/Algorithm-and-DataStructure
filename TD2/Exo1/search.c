#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
#include <math.h>

int jump_search(int *arr, int n, int target)
{
    //if (!is_sorted_nondecreasing(arr, n)) return -1;
    
    
    int step = (int)sqrt(n);
    
    int prev = 0;
    
    
    while (prev < n && arr[prev] < target) {
        prev += step;
    }
    
   
    int start = (prev > step) ? prev - step : 0;
    
   
    for (int i = start; i <= prev && i < n; i++) {
        if (arr[i] == target) return i;
        if (arr[i] > target) break;
    }
    
    return -1;
}

int binary_search(int *arr, int n, int target)
{
    //if (!is_sorted_nondecreasing(arr, n)) return -1;
    
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;  
        
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return -1;
}