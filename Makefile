OBJECTS = list01 list02 list03 list04 list05 list06 list07 list08 list09 list10 list11 list12 list17 task02

all: ${OBJECTS}

clean:
	rm -f ${OBJECTS}

list01: list01.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list02: list02.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list03: list03.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list04: list04.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list05: list05.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list06: list06.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list07: list07.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list08: list08.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list09: list09.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list10: list10.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list11: list11.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list12: list12.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list17: list17.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

task02: task02.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`