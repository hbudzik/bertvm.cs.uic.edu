

CC = g++
FLAGS = -std=c++11

SOURCES := $(wildcard t*.cpp)

EXECUTABLES = $(SOURCES:.cpp=)

all: $(EXECUTABLES)

% : %.cpp List.h _util.h _test.h 
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)

