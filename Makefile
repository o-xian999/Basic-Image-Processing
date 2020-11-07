OBJECTS = list01 list02 list03

all: ${OBJECTS}

clean:
	rm -f ${OBJECTS}

list01: list01.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list02: list02.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`

list03: list03.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`
