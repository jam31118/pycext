## Compiler
NVCC = nvcc


## Compilation Flags

cuda_lib_flags = -L/usr/local/cuda/lib64 -lcudart

# [NOTE] GeForce GTX 1080 and 1080 Ti can support SM60
cuda_opti_flags = -arch=sm_60

