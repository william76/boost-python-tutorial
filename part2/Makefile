include ../Make.defaults
include ../Make.rules

OBJS = handle_error.o

all: handle_error

handle_error: $(OBJS) $(BOOST_PYTHON_LIB)
	$(LD) -o handle_error $^ $(LDFLAGS) -lpython2.6

clean:
	rm -rf $(OBJS) handle_error



    
