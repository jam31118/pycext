#include <iostream>
#include <complex>
#include "array_add.hh"

int main() {

	long N = 10;
	double a[N], b[N], out[N];
  std::complex<double> ac[N], bc[N], outc[N];
	long index;
	for (index = 0; index < N; index++) {
		a[index] = index;
		b[index] = index * 0.5;

    ac[index] = std::complex<double>(0.1 * index, 0.2 * index);
    bc[index] = ac[index] * 2.0;
  }

	if ( add_array_double(a, b, out, N) != 0) {
		fprintf(stderr, "[ERROR] Failed to add array for double.\n");
		return 1;
	}

	if ( add_array_complex(ac, bc, outc, N) != 0) {
		fprintf(stderr, "[ERROR] Failed to add array for complex.\n");
		return 1;
	}

	for (index = 0; index < N; index++) {
		printf("%.2f + %.2f = %.2f\n", a[index], b[index], out[index]);
		printf("%.2f + %.2f = %.2f\n", ac[index].real(), bc[index].real(), outc[index].real());
	}

  return 0;
}
