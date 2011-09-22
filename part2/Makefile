include ../Make.defaults
include ../Make.rules

OBJS = handle_error.o

all: handle_error

handle_error: $(OBJS)
	$(LD) -o $@ $^ $(PY_LDFLAGS) $(LDFLAGS) $(BOOST_LDFLAGS)

clean:
	rm -rf $(OBJS) handle_error




