#include <Python.h>
#include <numpy/arrayobject.h>
#include "array_add.hh"
#include <complex>

extern "C" { static PyObject *_array_add_cc_add_array_general(PyObject *self, PyObject *args); }

static PyMethodDef module_methods[] = {
	{"add_array_general", _array_add_cc_add_array_general, METH_VARARGS, "Add general type array"}
};

static PyModuleDef _array_add_cc {
  PyModuleDef_HEAD_INIT,
  "_array_add_cc",
  "General type addition",
  -1,
  module_methods
};

extern "C" PyMODINIT_FUNC PyInit__array_add_cc(void) {
	import_array();
	return PyModule_Create(&_array_add_cc);
}

template <class T>
int add_array_core_template(PyObject *a_array, PyObject *b_array, PyObject *out_array, long N) {

  	T *a = (T *) PyArray_DATA(a_array);
	  T *b = (T *) PyArray_DATA(b_array);
  	T *out = (T *) PyArray_DATA(out_array);

    if ( add_array_general<T>(a, b, out, N) != 0 ) {
      PyErr_SetString(PyExc_Exception, "Failed to add array");
      return 1;
    }
    return 0;
}


static PyObject *_array_add_cc_add_array_general(PyObject *self, PyObject *args) {

	PyObject *a_obj, *b_obj, *out_obj;
	long N;

	if (!PyArg_ParseTuple(args, "OOO", &a_obj, &b_obj, &out_obj)) { 
		PyErr_SetString(PyExc_Exception, "Failed to parse argument tuple");
		return NULL; }

	PyObject *a_array = PyArray_FROM_OTF(a_obj, NPY_NOTYPE, NPY_IN_ARRAY);
	PyObject *b_array = PyArray_FROM_OTF(b_obj, NPY_NOTYPE, NPY_IN_ARRAY);
	PyObject *out_array = PyArray_FROM_OTF(out_obj, NPY_NOTYPE, NPY_OUT_ARRAY);

	if (a_array == NULL || b_array == NULL || out_array == NULL) {
		PyErr_SetString(PyExc_Exception, "Failed to get array object from input arguments");
		Py_XDECREF(a_array);
		Py_XDECREF(b_array);
		Py_XDECREF(out_array);
		return NULL;
	}



	N = (long) PyArray_DIM(a_array, 0);

  int typenum_a = PyArray_TYPE(a_array);
  int typenum_b = PyArray_TYPE(b_array);
  int typenum;
  if (typenum_a != typenum_b) {
    PyErr_SetString(PyExc_Exception, "Inconsistent typenum");
    goto fail;
  } else { typenum = typenum_a; }


  
  if (typenum == NPY_DOUBLE) {
    if (add_array_core_template<double>(a_array, b_array, out_array, N) != 0) { goto fail; }
  } else if (typenum == NPY_COMPLEX128) {
    if (add_array_core_template<std::complex<double>>(a_array, b_array, out_array, N) != 0) { goto fail; }
  } else {
    PyErr_SetString(PyExc_Exception, "Unexpected typenum");
    goto fail;
  }



  Py_INCREF(Py_None);

	Py_DECREF(a_array);
	Py_DECREF(b_array);
	Py_DECREF(out_array);

	return Py_None;

fail:
	Py_XDECREF(a_array);
	Py_XDECREF(b_array);
	Py_XDECREF(out_array);
	return NULL;
}

