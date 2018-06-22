include ../var.mk

all: libcuadd.so

libcuadd.so: cuda_add_array.o gpu_code.o
	$(CXX) -shared $^ -o $@ $(cuda_lib_flags) -fPIC

gpu_code.o: cuda_add_array.o
	$(NVCC) $^ -o $@ -dlink $(cuda_opti_flags) --compiler-options -fPIC

cuda_add_array.o: add.cu
	$(NVCC) $^ -o $@ -c $(cuda_opti_flags) -I../include -dc --compiler-options -fPIC

clean:
	$(RM) -f *.o *.so

