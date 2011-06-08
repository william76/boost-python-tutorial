include ../Make.defaults
include ../Make.rules

HWOBJS = hello_world.o
INCDIR += -I/opt/miserware-libs/Python26/include/python2.6

all: helloworld

helloworld: $(HWOBJS) $(BOOST_PYTHON_LIB)
	$(LD) -o hello_world $^ $(LDFLAGS) -lpython2.6

clean:
	rm -rf $(OBJS)



    
