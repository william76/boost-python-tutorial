include ../Make.defaults
include ../Make.rules

HWOBJS = hello_world.o

all: helloworld

helloworld: $(HWOBJS)
	$(LD) -o $@ $^ $(PY_LDFLAGS) $(LDFLAGS) $(BOOST_LDFLAGS)

clean:
	rm -rf $(HWOBJS) hello_world




