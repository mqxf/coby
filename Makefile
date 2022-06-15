sources = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp) 
objects = $(sources:.cpp=.o)
flags = -g -Wall -Wextra -lm -ldl -fPIC -rdynamic -std=c++17 -I/usr/lib/llvm-14/include -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -L/usr/lib/llvm-14/lib -lLLVM-14

cobyc: $(objects)
	g++ $(objects) $(flags) -o cobyc

%.o: %.cpp %.h
	g++ -c $(flags) $< -o $@

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
