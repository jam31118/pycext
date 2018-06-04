## Define variables
PY = python
BUILD_FLAGS = --inplace


## Define targets
all: _add

_add:
	$(PY) setup.py build_ext $(BUILD_FLAGS)

clean:
	rm -rf build/ *.so

