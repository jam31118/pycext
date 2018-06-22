## Compiler
NVCC = nvcc


## Python variables
PY_VENV_DIR = $(HOME)/py/venv/sci
PY_INCLUDE = /usr/include/python3.6
PY_NUMPY_INCLUDE = $(PY_VENV_DIR)/lib/python3.6/site-packages/numpy/core/include/numpy


## Compilation Flags
cuda_lib_flags = -L/usr/local/cuda/lib64 -lcudart

# [NOTE] GeForce GTX 1080 and 1080 Ti can support SM60
cuda_opti_flags = -arch=sm_60

py_include_flags = -I$(PY_INCLUDE) -I$(PY_NUMPY_INCLUDE)

