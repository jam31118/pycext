#include <Python.h>
#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t kb_interrupt = 0;

void kb_interrupt_handler(int sig) {
  printf("Received kb interrupt\n");
  kb_interrupt = 1;
}

int fibo(int n) {
  int a, b;
  if (kb_interrupt) return -1;
  else if (n < 2) return n;
  else if ((a = fibo(n - 1)) < 0) return -1;
  else if ((b = fibo(n - 2)) < 0) return -1;
  else return a + b;
}

PyObject *bboe_fibo(PyObject *self, PyObject *args) {
//  __sighandler_t prev;
  int n, result;
  if (!PyArg_ParseTuple(args, "i", &n))
    return NULL;
  if (signal(SIGINT, kb_interrupt_handler) == SIG_ERR) {
	  PyErr_SetString(PyExc_Exception, "[ERROR] Failed to set handler for SIGINT");
	  return NULL;
  }
  result = fibo(n);
//  signal(SIGINT, prev);
  if (result < 0) {
    PyErr_SetObject(PyExc_KeyboardInterrupt, NULL);
    return NULL;
  }
  return Py_BuildValue("i", result);
}

PyMethodDef bboe_methods[] = {
  {"fibo", bboe_fibo, METH_VARARGS, "Compute the nth Fibonacci number."},
  {NULL, NULL, 0, NULL}
};

// Define this module
static struct PyModuleDef bboe_module_def = {
	PyModuleDef_HEAD_INIT,
	"bboe",
	"A Fibonacci sequence evaluator",
	-1,
	bboe_methods
};

PyMODINIT_FUNC PyInit_bboe(void) {
	return PyModule_Create(&bboe_module_def);
}

