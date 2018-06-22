include ../var.mk

all: gpu_code.o

#libcuadd.a: cuda_add_array.o gpu_code.o
#	$(NVCC) rcs $^ -o $@

gpu_code.o: cuda_add_array.o
	$(NVCC) $^ -o $@ -dlink $(cuda_opti_flags)

cuda_add_array.o: add.cu
	$(NVCC) $< -o $@ -c $(cuda_opti_flags) -I../include

clean:
	$(RM) -f *.o *.a

