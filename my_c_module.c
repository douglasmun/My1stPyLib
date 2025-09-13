#include <Python.h>

// A simple C function to calculate factorial
long c_factorial(int n) {
    long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Wrapper function for Python, handles Python arguments and returns
static PyObject* py_factorial(PyObject* self, PyObject* args) {
    int n;
    // PyArg_ParseTuple parses the Python arguments.
    // "i" means it expects a single integer argument.
    if (!PyArg_ParseTuple(args, "i", &n)) {
        return NULL; // Return NULL on error
    }
    long result = c_factorial(n); // Call the C function
    // PyLong_FromLong converts a C long to a Python integer object.
    return PyLong_FromLong(result);
}

// Method definition table for the module
static PyMethodDef MyMethods[] = {
    // {"Python method name", C function pointer, Calling convention, "Docstring"}
    {"factorial", py_factorial, METH_VARARGS, "Calculates the factorial of an integer."},
    {NULL, NULL, 0, NULL} // Sentinel to mark the end of the list
};

// Module definition structure
static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT,
    "my_c_module", // Name of the module
    "A simple C extension module.", // Module documentation
    -1, // Size of per-interpreter state of the module
    MyMethods
};

// Module initialization function
// This function is the entry point for the module.
PyMODINIT_FUNC PyInit_my_c_module(void) {
    return PyModule_Create(&mymodule);
}
