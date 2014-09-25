#include <stdio.h>
#include <stdlib.h>

static char * doc = "chaos.c\n\
\n\
Usage: ./chaos <X0> <A> <Iterations>\n\
\n\
Runs Xt+1 = A*Xt*(1-Xt) for each t in 0 ... Iterations, with Xt0 = X0\n\
and prints the results to stdout.\n\
\n\
0 <= X <= 1\n\
0 <= A <= 4\n";

static long double x1 (long double x0, long double a) { return a*x0*(1-x0); }

int main(int argc, char * argv[]) {

	if (argc < 4) {
		printf(doc);
		return 1;
	}
	
	else {
		long double x0 = strtold(argv[1], NULL);
		long double  a = strtold(argv[2], NULL);
		long iters = strtol(argv[3], NULL, 10);
		long double * history;
		history = (long double *) calloc(2, sizeof(long double));
		history[0] = x0;
		
		long double xn;
		for (int i = 0; i < iters; i++) {
			xn = x1(history[i], a);
			history = realloc(history, ( i + 3 ) * sizeof(long double));
			history[i + 1] = x1(history[i], a);
			printf("%3d %25.20Lf %35.20Lf x 10^10\n", i, history[i], history[i]*10000000000);
		}
	}
}
