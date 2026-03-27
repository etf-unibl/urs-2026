CFLAGS := -Wall -I./inc
STATIC ?= 1
DESTDIR ?= .

ifeq ($(STATIC),1)
LDFLAGS := -static -L./lib -ltest
LIB_TARGET := lib/libtest.a
else
LDFLAGS := -L./lib -ltest
LIB_TARGET := lib/libtest.so
endif

app: src/app.o $(LIB_TARGET)
	$(CROSS_COMPILE)gcc src/app.o -o $@ $(LDFLAGS)

src/app.o: src/app.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

lib/libtest.a:
	$(MAKE) -C lib STATIC=$(STATIC) libtest.a

lib/libtest.so:
	$(MAKE) -C lib STATIC=$(STATIC) libtest.so

install: app
	mkdir -p $(DESTDIR)
	cp app $(DESTDIR)
ifneq ($(STATIC),1)
	cp lib/libtest.so $(DESTDIR)
endif

clean:
	rm -f app src/*.o
	$(MAKE) -C lib clean

.PHONY: clean install
