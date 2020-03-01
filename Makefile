
all: run

run:
	(cd build; make; ./cpwite)

clean:
	(cd build; make clean)

watch:
	(while true; do \
    make run -q || make run; sleep 0.5; \
  done)

.PHONY: clean

