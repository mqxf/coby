sources = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) 
objects = $(sources:.cpp=.o)
flags = -g -Wall -Wextra -lm -ldl -fPIC -rdynamic -std=c++17

cobyc: $(objects)
	g++ $(objects) $(flags) -o cobyc

%.o: %.c include/%.h
	g++ $(flags) $< -o $@ -c

install:
	make
	sudo cp ./cobyc /usr/local/bin/cobyc
	make clean

clean:
	-rm src/*.o
	-rm src/**/*.o
	-rm cobyc
	clear

lint:
	clang-tidy src/*.c src/include/*.h
