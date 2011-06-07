#include <boost/python.hpp>
#include <Python.h>

namespace py = boost::python;

int main(){
    // Must be called before any boost::python functions
    Py_Initialize();
    // import the main module
    py::object main_module = boost::python::import("__main__");
    // load the dictionary object out of the main module
    py::object main_namespace = main_module.attr("__dict__");
    // run code within the main namespace
    py::exec("print 'Hello, world'", main_namespace);
}
