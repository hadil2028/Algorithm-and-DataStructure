#include <stdio.h>
#include <time.h>
#include "fib.h"

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;
    
    printf("Entrez la valeur de n: ");
    scanf("%d", &n);
    
    // test algonaïf
    start = clock();
    long long result_naive = fib_naive(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Naif: F(%d) = %lld, Temps: %f secondes\n", n, result_naive, cpu_time_used);
    
    // test algor dynamique
    start = clock();
    long long result_dynamic = fib_dynamic(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Dynamique: F(%d) = %lld, Temps: %f secondes\n", n, result_dynamic, cpu_time_used);
    
    return 0;
}