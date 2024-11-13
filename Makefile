CXXFLAGS = -g -Wall --pedantic

main: build/main.o build/player.o build/points.o build/random_gen.o
	g++ build/main.o build/player.o build/points.o build/random_gen.o \
		-o coc \
		${CXXFALGS} \

build/main.o: src/main.cpp src/player.h src/points.h src/random_gen.h
	g++ src/main.cpp \
		-c -o build/main.o \
		${CXXFLAGS}

build/player.o: src/player.cpp src/player.h
	g++ src/player.cpp \
		-c -o build/player.o \
		${CXXFLAGS}

build/points.o: src/points.cpp src/points.h src/player.h
	g++ src/points.cpp \
		-c -o build/points.o \
		${CXXFLAGS}

build/random_gen.o: src/random_gen.o src/random_gen.h
	g++ src/random_gen.cpp \
		-c -o build/random_gen.o \
		${CXXFLAGS}

exe:
	echo && ./coc && echo

clean:
	rm build/*
