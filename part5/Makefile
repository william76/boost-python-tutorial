include ../Make.defaults
include ../Make.rules

HWOBJS = example.o

all: example.x

example.x: $(HWOBJS)
	$(LD) -o $@ $^ $(PY_LDFLAGS) $(LDFLAGS) $(BOOST_LDFLAGS)

clean:
	rm -rf $(HWOBJS) example.x




