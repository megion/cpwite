
all: run

run:
	cd build; make

watch:
	while true; do \
		make $(WATCHMAKE); \
        inotifywait -qre close_write .; \
    done

clean:
	cd build; make clean


.PHONY: clean

