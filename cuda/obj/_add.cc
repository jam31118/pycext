#include <Python.h>
#include "arrayobject.h"
#include <iostream>

#include "add.cuh"


extern "C" { static PyObject *cu_add_array(PyObject *self, PyObject *args); }
extern "C" PyMODINIT_FUNC PyInit__array_add(void);

static PyMethodDef module_methods[] = {
	{"add_array", cu_add_array, METH_VARARGS, "GPU ver. Add double-type array"},
  {NULL, NULL, 0, NULL}
};

static PyModuleDef cu = {
	PyModuleDef_HEAD_INIT,
	"cu",
	"A set of array arithmetics functions using GPU",
	-1,
	module_methods
};

PyMODINIT_FUNC PyInit_cu(void) {
	import_array();
	return PyModule_Create(&cu);
}


static PyObject *cu_add_array(PyObject *self, PyObject *args) {

  PyObject *a_obj, *b_obj, *out_obj;

	if (!PyArg_ParseTuple(args, "OO", &a_obj, &b_obj)) { 
		PyErr_SetString(PyExc_Exception, "Failed to parse argument tuple");
		return NULL; }

	PyObject *a_array = PyArray_FROM_OTF(a_obj, NPY_DOUBLE, NPY_IN_ARRAY);
	PyObject *b_array = PyArray_FROM_OTF(b_obj, NPY_DOUBLE, NPY_IN_ARRAY);

	long N = (long) PyArray_DIM(a_array, 0);

  long dims[1];
  dims[0] = N;

  PyArrayObject *result_array = (PyArrayObject *) PyArray_SimpleNew(1, dims, NPY_DOUBLE);

	double *a = (double *) PyArray_DATA(a_array);
	double *b = (double *) PyArray_DATA(b_array);
	double *result = (double *) PyArray_DATA(result_array);

  add_array(a, b, result, N);

  Py_DECREF(a_array);
  Py_DECREF(b_array);
  
  return PyArray_Return(result_array);
}

