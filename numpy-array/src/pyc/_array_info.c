#include <Python.h>
#include <numpy/arrayobject.h>
#include "array_add.h"

static PyObject *_array_info_get_dim(PyObject *self, PyObject *args);
static PyObject *_array_info_get_length(PyObject *self, PyObject *args);
static PyObject *_array_info_check_double_or_complex(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
	{"get_dim", _array_info_get_dim, METH_VARARGS, "Returns dimension of the given array"},
	{"get_length", _array_info_get_length, METH_VARARGS, "Returns length of an array"},
	{"check_double_or_complex", _array_info_check_double_or_complex, METH_VARARGS, "Check whether the given array is of type double or complex"},
	{NULL, NULL, 0, NULL}
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

	Py_DECREF(arr);
	
	return return_tuple;
}

static PyObject *_array_info_get_length(PyObject *self, PyObject *args) {
	PyObject *arr_obj;
	if (!PyArg_ParseTuple(args, "O", &arr_obj))	{ return NULL; }

	PyObject *arr = PyArray_FROM_OTF(arr_obj, NPY_NOTYPE, NPY_IN_ARRAY);
	if (arr == NULL) { return NULL; }

	int ndim = PyArray_NDIM(arr);
	if (ndim != 1) { 
		PyErr_SetString(PyExc_Exception, "ndim should be 1 for length to be defined"); 
		return NULL;
	}
	
	npy_intp arr_size = PyArray_SIZE(arr);
	PyObject *return_tuple = Py_BuildValue("i", arr_size);

	Py_DECREF(arr);

	return return_tuple;
}



static PyObject *_array_info_check_double_or_complex(PyObject *self, PyObject *args) {
	PyObject *arr_obj;
	if (!PyArg_ParseTuple(args, "O", &arr_obj))	{ return NULL; }

	PyObject *arr = PyArray_FROM_OTF(arr_obj, NPY_NOTYPE, NPY_IN_ARRAY);
	if (arr == NULL) { return NULL; }

  int typenum = PyArray_TYPE(arr);
  printf("typenum: %d\n", typenum);
  if (typenum == NPY_DOUBLE) { printf("The given array is of NPY_DOUBLE type\n"); }
  else if (typenum == NPY_COMPLEX128) { printf("The given array is of NPY_COMPLEX128 type \n"); }
  else { printf("The given array is of type neither NPY_DOUBLE nor NPY_COMPLEX128\n"); }

  Py_INCREF(Py_None);
  return Py_None;
}

