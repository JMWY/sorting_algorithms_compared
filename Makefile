# compiler
CC = gcc -std=gnu99

# target files
TARGET = demo

# path of head files
CFLAGS = -I./include

# load libm.so file
LIBS = -lm
# path of .so files
LDFLAGS = -L/usr/lib/x86_64-linux-gnu/ -Wl,R/usr/lib/x86_64-linux-gnu/
#LDFLAGS = -L/usr/lib -L/usr/lib/x86_64-linux-gnu/ -Wl,R/usr/lib -Wl,R/usr/lib/x86_64-linux-gnu/

# source files
source = $(wildcard *.c algorithms/*.c)
# generated object files
object = $(patsubst %.c,%.o,$(source))  
# dependent files [for 'make clean']
deps = $(source:.c=.d)

# generated target files
$(TARGET): ${object}
	$(CC) -g -W -Wall -o $@ $^ $(LIBS)
	@echo "Done"

# load *.d files, 'sinclude' is equal to '-include'
sinclude $(source:.c=.d)
%.d: %.c
	set -e; rm -f $@; \
	$(CC) $(CFLAGS) -MM $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

.PHONY: clean
clean:
	-rm -f $(object)
	-rm -f $(deps)
	-rm $(TARGET)
