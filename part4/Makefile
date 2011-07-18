include ../Make.defaults
include ../Make.rules

OBJS = handle_error.o parse_config.o config_parser.o

all: parse_config

parse_config: $(OBJS) $(BOOST_PYTHON_LIB)
	$(LD) -o parse_config $^ $(LDFLAGS) -lpython2.6

clean:
	rm -rf $(OBJS) parse_config



    
