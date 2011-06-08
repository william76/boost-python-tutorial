include ../Make.defaults
include ../Make.rules

HWOBJS = hello_world.o

all: helloworld

helloworld: $(HWOBJS) $(BOOST_PYTHON_LIB)
	$(LD) -o hello_world $^ $(LDFLAGS) -lpython2.6

clean:
	rm -rf $(HWOBJS) hello_world



    
