include ../var.mk

obj_dir = ../obj

targets = main

all: $(targets)


#Use only the shared library
#and now, start building python wrapper module and compile it into a shared library file


#main: main.cc $(obj_dir)/cuda_add_array.o $(obj_dir)/gpu_code.o
#	$(CXX) $^ -o $@ $(cuda_lib_flags) -I../include

main: main.cc $(obj_dir)/libcuadd.so
	$(CXX) $^ -o $@ $(cuda_lib_flags) -I../include -L../obj -lcuadd

$(obj_dir)/libcuadd.so:
	$(MAKE) -C $(obj_dir)

#$(obj_dir)/cuda_add_array.o:
#	$(MAKE) cuda_add_array.o -C $(obj_dir)

#$(obj_dir)/gpu_code.o:
#	$(MAKE) gpu_code.o -C $(obj_dir)

clean:
	$(MAKE) clean -C $(obj_dir)
	$(RM) -f $(targets)

