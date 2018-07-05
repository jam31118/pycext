#include <cstdio>
#include "add.cuh"

int main(int argc, char **argv) {
  long N = 10;
  double a[N], b[N], c[N];
  long i;
  for (i=0; i<N; i++) { a[i] = i; b[i] = 2 * i; }
  
  add_array(a, b, c, N);

  for (i=0; i<N; i++) { fprintf(stdout, "[%03ld] %.2f + %.2f = %.2f\n", i, a[i], b[i], c[i]); }

  return 0;
}

