#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <boost/python.hpp>

class ConfigParser{
    private:
        boost::python::object conf_parser_;

        void init_py();
        bool parse_file_py(const std::string &filename);
        std::string get_py(const std::string &attr,
                           const std::string &section = "DEFAULT");
        void set_py(const std::string &attr, 
                    const std::string &value,
                    const std::string &section = "DEFAULT");
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
