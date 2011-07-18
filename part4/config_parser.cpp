#include "config_parser.h"
#include "handle_error.h"

using namespace std;
namespace py = boost::python;

ConfigParser::ConfigParser(){
    call_python_func<void>(boost::bind(&ConfigParser::init_py, this), 
                           "Error during configuration parser init: ");
}

void ConfigParser::init_py(){
    // load the main namespace
    py::object mm = py::import("__main__");
    // load the dictionary for the namespace
    py::object mn = mm.attr("__dict__");
    // import the ConfigParser module into the namespace
    py::exec("import ConfigParser", mn); 
    // create the locally-held RawConfigParser object
    conf_parser_ = py::eval("ConfigParser.RawConfigParser()", mn);
}

bool ConfigParser::parse_file_py(const string &filename){
    // return true if we have successfully parsed the file
    return py::len(conf_parser_.attr("read")(filename)) == 1;
}

bool ConfigParser::parse_file(const string &filename){
    return call_python_func<bool>(boost::bind(&ConfigParser::parse_file_py, this, filename), 
                                  "Error during configuration file parsing: ");
}

string ConfigParser::get_py(const string &attr, const string &section){
    // extract the string value of the attribute within the given section
    return py::extract<string>(conf_parser_.attr("get")(section, attr));
}

string ConfigParser::get(const string &attr, const string &section){
    return call_python_func<string>(boost::bind(&ConfigParser::get_py, this, attr, section),
                                  "Error getting configuration option: ");
}

void ConfigParser::set_py(const string &attr, const string &value, const string &section){
    // set the string value of the attribute within the given section
    conf_parser_.attr("set")(section, attr, value);
}

void ConfigParser::set(const string &attr, const string &value, const string &section){
    call_python_func<void>(boost::bind(&ConfigParser::set_py, this, attr, value, section),
                           "Error setting configuration option: ");
}
