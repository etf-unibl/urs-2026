CFLAGS := -Wall -I./inc
LDFLAGS := -L./lib

STATIC ?= 1

ifeq ($(STATIC),1)
    LDFLAGS += -static -ltest
    LIB = lib/libtest.a
else
    LDFLAGS += -ltest
    LIB = lib/libtest.so
endif

app: src/app.o $(LIB)
	$(CROSS_COMPILE)gcc src/app.o -o $@ $(LDFLAGS)

src/app.o: src/app.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

lib/libtest.a:
	$(MAKE) -C lib STATIC=1 libtest.a

lib/libtest.so:
	$(MAKE) -C lib STATIC=0 libtest.so

install:
	mkdir -p $(DESTDIR)
	cp app $(DESTDIR)

clean:
	rm -f app src/*.o
	$(MAKE) -C lib clean

.PHONY: clean install