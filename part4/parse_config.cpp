#include <Python.h>
#include <iostream>
#include <boost/python.hpp>
#include "config_parser.h"

namespace py = boost::python;
using namespace std;

std::string parse_python_exception();

int main(){
    Py_Initialize();
    try{
        ConfigParser parser;
        // Parse the first file
        parser.parse_file("conf_file.1.conf");
        // Read a value out of the first file
        cout << "Directory (file 1): " << parser.get("Directory", "DEFAULT") << endl;
        // Parse the second file
        parser.parse_file("conf_file.2.conf");
        // Read the (overridden) same value 
        cout << "Directory (file 2): " << parser.get("Directory", "DEFAULT") << endl;
        // Read some values out of non-DEFAULT sections
        cout << "Username: " << parser.get("Username", "Auth") << endl;
        cout << "Password: " << parser.get("Password", "Auth") << endl;
        // Set a value and re-read
        parser.set("Directory", "values can be arbitrary strings", "DEFAULT");
        cout << "Directory (force set by application): " << parser.get("Directory") << endl;

        // Will raise a NoOption exception 
         cout << "Proxy host: " << parser.get("ProxyHost", "Network") << endl;
    }catch(exception &e){
        // The python error string will be in the thrown exception
        cout << "Here is the error, from a C++ exception: " << e.what() << endl;
    }
}
