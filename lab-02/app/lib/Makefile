CFLAGS := -Wall -I../inc
SRCS_DIR := ../src
STATIC ?= 1

ifeq ($(STATIC),1)

libtest.a: print.o sum.o
	$(CROSS_COMPILE)ar rcs $@ $^

print.o: $(SRCS_DIR)/print.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

sum.o: $(SRCS_DIR)/sum.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

else

libtest.so: print.o sum.o
	$(CROSS_COMPILE)gcc -shared print.o sum.o -o $@

print.o: $(SRCS_DIR)/print.c
	$(CROSS_COMPILE)gcc -c -fPIC $< $(CFLAGS) -o $@

sum.o: $(SRCS_DIR)/sum.c
	$(CROSS_COMPILE)gcc -c -fPIC $< $(CFLAGS) -o $@

endif

clean:
	rm -f *.o libtest.a libtest.so

.PHONY: clean
