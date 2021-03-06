#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int number_of_primes(int n) {
	int p = 0;

	// for the sake of readability, we align the indexing with the actual numbers
	int is_prime[n+1];
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= n; i++) {
		is_prime[i] = 1;
	}

	// use the sieve of Erathosthenes
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			p++;
			int j = i + i;
			while (j <= n) {
				is_prime[j] = 0;
				j += i;
			}
		}
	}

	return p;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Usage: primes <n>\n");
		return -1;
	}
	const int n = strtol(argv[1], NULL, 10);

	printf("Calculating:\n");
	int p = number_of_primes(n);
	printf("Done.\n");
	printf("There are %d primes between 1 and %d.\n", p, n);

	return 0;
}
