#include <boost/python.hpp>
#include <string>

namespace py = boost::python;

std::string parse_python_exception();

template <class return_type>
return_type call_python_func(boost::function<return_type ()> to_call, const std::string &error_pre){
    // Prefix the error string
    std::string error_str(error_pre);

    try{
        return to_call();
    }catch(boost::python::error_already_set const &){
        // Handle the error here, repackage as a C++ error
        error_str = error_str + parse_python_exception();
        throw std::runtime_error(error_str);
    }
}
