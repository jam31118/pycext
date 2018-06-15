## Define variables
PY = python
BUILD_FLAGS = --inplace


## Define targets
all: _add

_add:
	$(PY) setup.py build_ext $(BUILD_FLAGS)

clean:
	rm -rf build/ *.so

clean-dist:
	rm -rf dist/ *.egg-info

clean-all: clean clean-dist

