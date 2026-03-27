CFLAGS := -Wall -I../inc
SRCS_DIR := ../src

STATIC ?= 1

OBJS = print.o sum.o

libtest.a: $(OBJS)
	$(CROSS_COMPILE)ar rcs $@ $^

libtest.so: $(OBJS)
	$(CROSS_COMPILE)gcc -shared -o $@ $^

%.o: $(SRCS_DIR)/%.c
ifeq ($(STATIC),1)
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@
else
	$(CROSS_COMPILE)gcc -c -fPIC $< $(CFLAGS) -o $@
endif

clean:
	rm -f *.o libtest*

.PHONY: clean