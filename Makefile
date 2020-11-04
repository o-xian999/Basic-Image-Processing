OBJECTS = list01

all: ${OBJECTS}

clean:
	rm -f ${OBJECTS}

list01: list01.c
	${CXX} $^ -o $@ `pkg-config --cflags --libs opencv4`
