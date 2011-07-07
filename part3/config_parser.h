#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <boost/python.hpp>

class ConfigParser{
    private:
        boost::python::object conf_parser_;
    public:
        ConfigParser();

        bool parse_file(const std::string &filename);
        std::string get(const std::string &attr,
                        const std::string &section = "DEFAULT");
        void set(const std::string &attr, 
                 const std::string &value,
                 const std::string &section = "DEFAULT");
};

#endif
