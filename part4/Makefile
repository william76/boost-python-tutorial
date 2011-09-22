include ../Make.defaults
include ../Make.rules

OBJS = handle_error.o parse_config.o config_parser.o

all: parse_config

parse_config: $(OBJS)
	$(LD) -o $@ $^ $(PY_LDFLAGS) $(LDFLAGS) $(BOOST_LDFLAGS)

clean:
	rm -rf $(OBJS) parse_config




