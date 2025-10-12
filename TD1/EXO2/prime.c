#include <math.h>
#include <stdlib.h>
#include "prime.h"

// la méthode naïve
int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// méthode naïve
int count_primes_naive(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime(i))
            count++;
    }
    return count;
}

// efficient one
int count_primes_sieve(int n) {
    if (n <= 2) return 0;

    int* is_prime = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        is_prime[i] = 1; 
    }

    is_prime[0] = is_prime[1] = 0; 

    for (int i = 2; i * i < n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < n; j += i) {
                is_prime[j] = 0; 
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime[i])
            count++;
    }

    free(is_prime);
    return count;
}
