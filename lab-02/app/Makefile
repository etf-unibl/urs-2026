STATIC ?= 1

DESTDIR ?= output/

ifeq ($(STATIC), 1)
    LDFLAGS := -static -L./lib -ltest
    LIB_TARGET := libtest.a
else
    LDFLAGS := -L./lib -ltest
    LIB_TARGET := libtest.so
endif

CFLAGS := -Wall -I./inc

.PHONY: all clean install STATIC DYNAMIC

all: app

STATIC:
	$(MAKE) STATIC=1 app

DYNAMIC:
	$(MAKE) STATIC=0 app

app: src/app.o lib/$(LIB_TARGET)
	$(CROSS_COMPILE)gcc src/app.o -o $@ $(LDFLAGS)

src/app.o: src/app.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

lib/libtest.a:
	$(MAKE) -C lib libtest.a

lib/libtest.so:
	$(MAKE) -C lib libtest.so

install: app
	mkdir -p "$(DESTDIR)"
	cp app "$(DESTDIR)/"

clean:
	rm -f app src/*.o
	$(MAKE) -C lib clean