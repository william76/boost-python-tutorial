include ../Make.defaults
include ../Make.rules

OBJS = main.o
INCDIR += -I../micromiser -I/opt/miserware-libs/Python26/include/python2.6

all: $(OBJS) $(BOOST_PYTHON_LIB)
	$(LD) -o part1 $^ $(LDFLAGS) -lpython2.6

clean:
	rm -rf $(OBJS)



    
