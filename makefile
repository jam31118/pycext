## Define variables
PY = python
BUILD_FLAGS = --inplace


## Define targets
all: _add

_add:
	$(PY) setup.py build_ext $(BUILD_FLAGS)

clean:
	rm -rf build/
	find . -name "*.so" -delete
	#find . -name "__pycache__" -delete
	for d in $(find . -name "__pycache__"); do echo $d; rm -rf $d; done

clean-dist:
	rm -rf dist/ *.egg-info

clean-all: clean clean-dist

