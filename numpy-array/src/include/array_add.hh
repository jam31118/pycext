#ifndef _ARRAY_ADD_HH_
#define _ARRAY_ADD_HH_

#include <complex>

template <class T>
int add_array_general(T *a, T *b, T *c, long N) {
  long i;
  T *p_a, *p_b, *p_c;
  for (i=0, p_a=a, p_b=b, p_c=c; i < N; ++i, ++p_a, ++p_b, ++p_c) {
    *p_c = *p_a + *p_b;
  }
  return 0;
}

extern "C" int add_array_type_double(double *a, double *b, double *c, long N);

extern "C" int add_array_type_complex(std::complex<double> *a, std::complex<double> *b, std::complex<double> *c, long N);

#endif // _ARRAY_ADD_HH_
