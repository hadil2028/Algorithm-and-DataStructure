#include <stdio.h>
#include <time.h>
#include "prime.h"

int main() {
    int n;
    printf("Entrer un entier n : ");
    scanf("%d", &n);

    clock_t start, end;
    double time_naive, time_sieve;

    // methode naïve
    start = clock();
    int count_naive = count_primes_naive(n);
    end = clock();
    time_naive = (double)(end - start) / CLOCKS_PER_SEC;

    // mehode efficace (crible)
    start = clock();
    int count_sieve = count_primes_sieve(n);
    end = clock();
    time_sieve = (double)(end - start) / CLOCKS_PER_SEC;

    // results
    printf("\n results \n");
    printf("methode naïve : %d nombres premiers trouvés en %.6f secondes.\n", count_naive, time_naive);
    printf("methode efficace (Crible) : %d nombres premiers trouvés en %.6f secondes.\n", count_sieve, time_sieve);

    return 0;
}
