include ../var.mk

obj_dir = ../obj

targets = main

all: $(targets)

main: main.cc $(obj_dir)/cuda_add_array.o $(obj_dir)/gpu_code.o
	$(CXX) $^ -o $@ $(cuda_lib_flags) -I../include

$(obj_dir)/cuda_add_array.o:
	$(MAKE) cuda_add_array.o -C $(obj_dir)

$(obj_dir)/gpu_code.o:
	$(MAKE) -C $(obj_dir)

clean:
	$(MAKE) clean -C $(obj_dir)
	$(RM) -f $(targets)

