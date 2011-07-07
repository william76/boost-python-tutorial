#include "config_parser.h"

namespace py = boost::python;

ConfigParser::ConfigParser(){
    // load the main namespace
    py::object mm = py::import("__main__");
    // load the dictionary for the namespace
    py::object mn = mm.attr("__dict__");
    // import the ConfigParser module into the namespace
    py::exec("import ConfigParser", mn); 
    // create the locally-held RawConfigParser object
    conf_parser_ = py::eval("ConfigParser.RawConfigParser()", mn);
}

bool ConfigParser::parse_file(const std::string &filename){
    // return true if we have successfully parsed the file
    return py::len(conf_parser_.attr("read")(filename)) == 1;
}

std::string ConfigParser::get(const std::string &attr, const std::string &section){
    // extract the string value of the attribute within the given section
    return py::extract<std::string>(conf_parser_.attr("get")(section, attr));
}

void ConfigParser::set(const std::string &attr, const std::string &value, const std::string &section){
    // set the string value of the attribute within the given section
    conf_parser_.attr("set")(section, attr, value);
}
