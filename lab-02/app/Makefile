CFLAGS := -Wall -I./inc
STATIC ?= 1

ifeq ($(STATIC), 1)
    LDFLAGS := -static -L./lib -ltest
    DEPS := src/app.o lib/libtest.a
else
    LDFLAGS := -L./lib -ltest -Wl,-rpath,./lib
    DEPS := src/app.o lib/libtest.so
endif


app: $(DEPS)
	$(CROSS_COMPILE)gcc src/app.o -o $@ $(LDFLAGS)

src/app.o: src/app.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

lib/libtest.a:
	$(MAKE) -C lib libtest.a

lib/libtest.so:
	$(MAKE) -C lib libtest.so

clean:
	rm -f app src/*.o
	$(MAKE) -C lib clean

install: app
	@if [ ! -d "$(DESTDIR)" ]; then \
		echo "Error: Directory $(DESTDIR) not foudn!"; \
		exit 1; \
	fi
	cp app $(DESTDIR)
	sync
	@echo "Executable copied successfully."

.PHONY: clean install

