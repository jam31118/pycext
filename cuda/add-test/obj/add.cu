#include "add.cuh"

extern "C" {

#define cudaErrchk(ans) { GPUAssert((ans), __FILE__, __LINE__); }
inline void GPUAssert(cudaError_t code, const char *file, int line, bool abort=true){
	if (code != cudaSuccess)
	{
		fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
		if (abort) exit(code);
	}
}


__global__ void add_array_d(double *a, double *b, double *c, long N) {
  long i = blockIdx.x * blockDim.x + threadIdx.x;  // an element_index
  if (i < N) { *(c+i) = *(a+i) + *(b+i); }
}


int add_array(double *a, double *b, double *c, long N) {
  
  double *a_d, *b_d, *c_d;

  size_t array_size_in_byte = N * sizeof(double);
  cudaErrchk( cudaMalloc(&a_d, array_size_in_byte) );
  cudaErrchk( cudaMalloc(&b_d, array_size_in_byte) );
  cudaErrchk( cudaMalloc(&c_d, array_size_in_byte) );

  cudaErrchk( cudaMemcpy(a_d, a, array_size_in_byte, cudaMemcpyHostToDevice) );
  cudaErrchk( cudaMemcpy(b_d, b, array_size_in_byte, cudaMemcpyHostToDevice) );

  int block_size = 32;
  int grid_size = (N + block_size - 1) / block_size;
  add_array_d<<<grid_size,block_size>>>(a_d, b_d, c_d, N);

  cudaErrchk( cudaMemcpy(c, c_d, array_size_in_byte, cudaMemcpyDeviceToHost) );
  
  cudaFree(a_d);
  cudaFree(b_d);
  cudaFree(c_d);

  return 0;
}

}
