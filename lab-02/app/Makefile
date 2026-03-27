CFLAGS := -Wall -I./inc

ifeq ($(STATIC), 1)
LDFLAGS := -static -L./lib -ltest 
LIBNAME := libtest.a
else
LDFLAGS := -L./lib -ltest
LIBNAME := libtest.so
endif

app: src/app.o lib/$(LIBNAME)
	$(CROSS_COMPILE)gcc src/app.o -o $@ $(LDFLAGS)

src/app.o: src/app.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

lib/$(LIBNAME):
	$(MAKE) -C lib $(LIBNAME)

clean:
	rm -f app src/*.o
	$(MAKE) -C lib clean

install: app
ifeq ($(strip $(DESTDIR)),)
	@echo "DESTDIR is empty, unable to install"
else
	cp app $(DESTDIR)
	@echo "Installed successfully"
endif

.PHONY: clean
