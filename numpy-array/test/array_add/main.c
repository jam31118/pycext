#include <stdio.h>

#include "array_add.h"


int main() {
	long N = 10;
	double a[N], b[N], out[N];
	long index;
	for (index = 0; index < N; index++) {
		a[index] = index;
		b[index] = index * 0.5;
	}

	if ( add_array_double(a, b, out, N) != 0) {
		fprintf(stderr, "[ERROR] Failed to add array.\n");
		return 1;
	}

	for (index = 0; index < N; index++) {
		printf("%.2f + %.2f = %.2f\n", a[index], b[index], out[index]);
	}
	

}
