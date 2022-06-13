sources = $(wildcard src/**/*.cpp) $(wildcard src/*.cpp)
objects = $(sources:.cpp=.o)
flags = -g -Wall -Wextra -lm -ldl -fPIC -rdynamic

cobyc: $(objects)
	g++ $(objects) $(flags) -o coby

%.o: %.c include/%.h
	g++ -c $(flags) $< -o $@

install:
	make
	sudo cp ./coby /usr/local/bin/coby
	make clean

clean:
	-rm src/*.o
	-rm src/**/*.o
	-rm coby
	clear

lint:
	clang-tidy src/*.c src/include/*.h
