#ifndef _ARRAY_ADD_HH_
#define _ARRAY_ADD_HH_

#include <complex>

extern "C" int add_array_type_double(double *a, double *b, double *c, long N);

extern "C" int add_array_type_complex(std::complex<double> *a, std::complex<double> *b, std::complex<double> *c, long N);

#endif // _ARRAY_ADD_HH_
