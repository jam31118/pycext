#include <Python.h>
#include <numpy/arrayobject.h>
#include "array_add.h"

static PyObject *_array_info_get_dim(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
	{"get_dim", _array_info_get_dim, METH_VARARGS, "Returns dimension of the given array"}
};

static PyModuleDef _array_info = {
	PyModuleDef_HEAD_INIT,
	"_array_info",
	"A set of array query functions",
	-1,
	module_methods
}; 

PyMODINIT_FUNC PyInit__array_info(void) {
	import_array();
	return PyModule_Create(&_array_info);
}


static PyObject *_array_info_get_dim(PyObject *self, PyObject *args) {

	PyObject *arr_obj;
	if (!PyArg_ParseTuple(args, "O", &arr_obj))	{ return NULL; }

	PyObject *arr = PyArray_FROM_OTF(arr_obj, NPY_NOTYPE, NPY_IN_ARRAY);
	if (arr == NULL) { return NULL; }

	int ndim = PyArray_NDIM(arr);
	PyObject *return_tuple = Py_BuildValue("i", ndim);
	
	return return_tuple;
}


