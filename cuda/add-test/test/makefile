include ../var.mk

obj_dir = ../obj

targets = main

all: $(targets)

main: main.cc $(obj_dir)/libcuadd.so
	$(CXX) $^ -o $@ $(cuda_lib_flags) -I../include -L../obj -lcuadd

$(obj_dir)/libcuadd.so:
	$(MAKE) -C $(obj_dir)

clean:
	$(MAKE) clean -C $(obj_dir)
	$(RM) -f $(targets)

