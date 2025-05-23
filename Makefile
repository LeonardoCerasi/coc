CXXFLAGS = -std=c++11 -g -Wall --pedantic
BUILD = if [ ! -d "build" ]; then mkdir build; fi

main: build/main.o build/player.o build/points.o
	${BUILD}
	g++ build/main.o build/player.o build/points.o \
		-o coc \
		${CXXFALGS} \

build/main.o: src/main.cpp src/player.h src/points.h
	${BUILD}
	g++ src/main.cpp \
		-c -o build/main.o \
		${CXXFLAGS}

build/player.o: src/player.cpp src/player.h
	${BUILD}
	g++ src/player.cpp \
		-c -o build/player.o \
		${CXXFLAGS}

build/points.o: src/points.cpp src/points.h src/player.h
	${BUILD}
	g++ src/points.cpp \
		-c -o build/points.o \
		${CXXFLAGS}

exe:
	echo && ./coc && echo

clean:
	rm build/*
