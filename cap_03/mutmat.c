/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Qij = U ^ Hij * (1 - U) ^ (L - Hij)                                                     *
 * where Qij is the probability that a replications of sequence i results in sequence j;   *
 * Hij is the Hamming distance between sequences i and j;                                  *
 * U is the probability that a mutation occurs in a given position;                        *
 * 1 - U is the probability that the sequence is copied correctly;                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns a substring from string of given size, starting at given position
static char * substr(char string[], int start, int size) {
	char sub[size + size/2];
	for ( int s = 0; s < size; s++ ) { sub[s] = string[s+start]; }
	sub[size] = '\0';
	char * subr = sub;
	return subr;
}

// Returns the Hamming distance between strings i and j
static int hamming(char * stringi, char * stringj) {
	if (strlen(stringi) != strlen(stringj)) {
		printf("different sizes\n");
		return -1;
	} else {
		int hamming = 0;
		for (int p = 0; p < strlen(stringi); p ++) {
			if ( stringi[p] != stringj[p] ) { hamming ++; }
		}
		return hamming;
	}
}

// Utility print int function - remove later
void puti(int i) { printf("%d\n", i); }

// Returns a score based on the contents of a given string
static int score(char * string) {
	int score = 0;
	for ( int p = 0; p < strlen(string); p++) {
		if (string[p] == '1') {
			score ++;
		}
	}
	return score;
}

int main ( int argc, char * argv[] ) {
	int a = hamming(argv[1], argv[2]);
	int s1 = score(argv[1]);
	int s2 = score(argv[2]);
	printf("hamming: %d\nscore 1: %d\nscore 2: %d\n", a, s1, s2);
	return 0;
}

