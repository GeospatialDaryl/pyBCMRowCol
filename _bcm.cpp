#include <Python.h>
#include <numpy/arrayobject.h>
#include "bcm.hpp"

/* Docstrings */
static char module_docstring[] =
    "This module provides an interface for calculating chi-squared using C.";
static char bcm_docstring[] =
    "Calculate the chi-squared of some data given a model.";

/* Available functions */
// static PyObject * bcm_bcm(
    // PyObject *self, 
    // PyObject *args);
static PyObject * bcm_Row(
    PyObject *self, 
    PyObject *args);
static PyObject * bcm_Col(
    PyObject *self, 
    PyObject *args);
/* Module specification */
static PyMethodDef module_methods[] = {
    {"", bcm_bcm, METH_VARARGS, bcm_docstring},
    {NULL, NULL, 0, NULL}
};

/* Initialize the module */
PyMODINIT_FUNC init_bcm(void)
{
    PyObject *m = Py_InitModule3("_bcm", module_methods, module_docstring);
    if (m == NULL)
        return;

    /* Load `numpy` functionality. */
    import_array();
}
static PyObject *bcm_Row(PyObject *self, PyObject *args){
    //  return int from double - inYCoord  
    double inYCoord;
    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, "d", &inYCoord ))
        return NULL;

    /*   calc value */
    int row = RowFromYCoord(inYCoord);
    
        /* Build the output tuple */
    PyObject *ret = Py_BuildValue("i", row);
    return ret;
}
static PyObject *bcm_Col(PyObject *self, PyObject *args){
    //  return int from double - inXCoord  
    double inXCoord;
    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, "d", &inXCoord ))
        return NULL;

    /*   calc value */
    int col = RowFromYCoord(inXCoord);
    
        /* Build the output tuple */
    PyObject *ret = Py_BuildValue("i", col);
    return ret;

}
// static PyObject *bcm_bcm(PyObject *self, PyObject *args)
// {
    // double m, b;
    // PyObject *x_obj, *y_obj, *yerr_obj;

    // /* Parse the input tuple */
    // if (!PyArg_ParseTuple(args, "ddOOO", &m, &b, &x_obj, &y_obj,
                                         // &yerr_obj))
        // return NULL;

    // /* Interpret the input objects as numpy arrays. */
    // PyObject *x_array = PyArray_FROM_OTF(x_obj, NPY_DOUBLE, NPY_IN_ARRAY);
    // PyObject *y_array = PyArray_FROM_OTF(y_obj, NPY_DOUBLE, NPY_IN_ARRAY);
    // PyObject *yerr_array = PyArray_FROM_OTF(yerr_obj, NPY_DOUBLE,
                                            // NPY_IN_ARRAY);

    // /* If that didn't work, throw an exception. */
    // if (x_array == NULL || y_array == NULL || yerr_array == NULL) {
        // Py_XDECREF(x_array);
        // Py_XDECREF(y_array);
        // Py_XDECREF(yerr_array);
        // return NULL;
    // }

    // /* How many data points are there? */
    // int N = (int)PyArray_DIM(x_array, 0);

    // /* Get pointers to the data as C-types. */
    // double *x    = (double*)PyArray_DATA(x_array);
    // double *y    = (double*)PyArray_DATA(y_array);
    // double *yerr = (double*)PyArray_DATA(yerr_array);

    // /* Call the external C function to compute the chi-squared. */
    // double value = bcm(m, b, x, y, yerr, N);

    // /* Clean up. */
    // Py_DECREF(x_array);
    // Py_DECREF(y_array);
    // Py_DECREF(yerr_array);

    // if (value < 0.0) {
        // PyErr_SetString(PyExc_RuntimeError,
                    // "Chi-squared returned an impossible value.");
        // return NULL;
    // }

    // /* Build the output tuple */
    // PyObject *ret = Py_BuildValue("d", value);
    // return ret;
// }