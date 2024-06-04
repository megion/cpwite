
all: run

run:
	(cd build; make; ./cpwite)

clean:
	(cd build; make clean)

.PHONY: clean
