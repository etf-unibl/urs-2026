CFLAGS  := -Wall -I./inc
LDFLAGS := -L./lib -ltest

STATIC ?= 1

ifeq ($(STATIC),0)
    LIB_TARGET := lib/libtest.so
else
    LDFLAGS   += -static
    LIB_TARGET := lib/libtest.a
endif

app: src/app.o $(LIB_TARGET)
	$(CROSS_COMPILE)gcc src/app.o -o $@ $(LDFLAGS)

src/app.o: src/app.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

lib/libtest.a:
	$(MAKE) -C lib STATIC=$(STATIC)

lib/libtest.so:
	$(MAKE) -C lib STATIC=$(STATIC)

install: app
	mkdir -p $(DESTDIR)
	cp app $(DESTDIR)

clean:
	rm -f app src/*.o
	$(MAKE) -C lib clean

.PHONY: clean install
