CFLAGS_COMMON := -Wall -I../inc
SRCS_DIR := ../src
OBJS := print.o sum.o

STATIC ?= 1

ifeq ($(STATIC),0)
    CFLAGS := $(CFLAGS_COMMON) -fPIC
    TARGET := libtest.so
else
    CFLAGS := $(CFLAGS_COMMON)
    TARGET := libtest.a
endif

all: $(TARGET)

libtest.a: $(OBJS)
	$(CROSS_COMPILE)ar rcs $@ $^

libtest.so: $(OBJS)
	$(CROSS_COMPILE)gcc -shared -o $@ $^

%.o: $(SRCS_DIR)/%.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

clean:
	rm -f *.o libtest.a libtest.so

.PHONY: all clean