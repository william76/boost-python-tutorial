#include <iostream>
#include <string>
#include <vector>

#include <boost/python.hpp>
#include <Python.h>

namespace py = boost::python;

int main(int argc, char * argv[])
{
    Py_Initialize();
    py::object main_module    = py::import("__main__");
    py::object main_namespace = main_module.attr("__dict__");

    // Execute the python script
    py::exec_file("example.py", main_namespace);

    // Call the stringlist() function from example.py.
    // - returns a list:  ['foo','bar','baz']
    py::object pyStringList = py::eval("stringlist()", main_namespace);

    // Verify the length of the returned list
    std::cout << "Length of list: " << py::len(pyStringList) << std::endl;

    // Print out the list contents
    for(int i=0; i<py::len(pyStringList); i++)
        {
        std::string value = py::extract<std::string>(pyStringList[i]);
        std::cout << i << "\t" << value << std::endl;
        }

    return 0;
}
