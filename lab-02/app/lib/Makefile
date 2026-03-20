CFLAGS := -Wall -I../inc -fPIC
SRCS_DIR := ../src

.PHONY: clean all

all: libtest.a libtest.so

libtest.a: print.o sum.o
	$(CROSS_COMPILE)ar rcs $@ $^

libtest.so: print.o sum.o
	$(CROSS_COMPILE)gcc -shared -o $@ $^

%.o: $(SRCS_DIR)/%.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

clean:
	rm -f *.o libtest.a libtest.so