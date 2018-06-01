#include <Python.h>
#include "add.h"

static PyObject *_add_add(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
	{"add", _add_add, METH_VARARGS, "Add doubles"}
};

static struct PyModuleDef _add = {
	PyModuleDef_HEAD_INIT,
	"_add",
	"_add modules doc?",
	-1,
	module_methods
};

PyMODINIT_FUNC PyInit__add(void) {
	return PyModule_Create(&_add);
}

//PyMODINIT_FUNC init_add(void) {
//	PyObject *m = Py_InitModule3("_add", module_methods, "Add Module");
//	if (m == NULL) { return NULL; }
//}

static PyObject *_add_add(PyObject *self, PyObject *args) {
	double a, b;
	if (!PyArg_ParseTuple(args, "dd", &a, &b)) { return NULL; }

	double result_value = add(a, b);

	PyObject *result_tuple = Py_BuildValue("d", result_value);
	return result_tuple;
};


