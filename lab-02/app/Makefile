CFLAGS := -Wall -I./inc
LDFLAGS := -static -ltest -L./lib

STATIC ?= 1

ifeq ($(STATIC), 1)
    LDFLAGS := -static -ltest -L./lib
    TARGET_NAME := app_static
    LIB_TARGET := lib/libtest.a
else
    LDFLAGS := -ltest -L./lib
    TARGET_NAME := app_dynamic
    LIB_TARGET := lib/libtest.so
    CFLAGS += -fPIC
endif

$(TARGET_NAME): src/app.o $(LIB_TARGET)
	$(CROSS_COMPILE)gcc src/app.o -o $@ $(LDFLAGS)

src/app.o: src/app.c
	$(CROSS_COMPILE)gcc -c $< $(CFLAGS) -o $@

lib/libtest.a:
	$(MAKE) -C lib libtest.a CROSS_COMPILE=$(CROSS_COMPILE)

lib/libtest.so:
	$(MAKE) -C lib libtest.so CROSS_COMPILE=$(CROSS_COMPILE)

clean:
	rm -f app_static app_dynamic src/*.o
	$(MAKE) -C lib clean

DESTDIR ?= ./install_dir

install: $(TARGET_NAME)
	@echo "INstalling $(TARGET_NAME) in $(DESTDIR)..."
	mkdir -p $(DESTDIR)
	cp $(TARGET_NAME) $(DESTDIR)
ifeq ($(STATIC), 0)
	@echo "Copzing dznamic..."
	cp lib/libtest.so $(DESTDIR)
endif

.PHONY: clean install

