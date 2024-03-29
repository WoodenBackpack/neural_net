INC="."

SOURCES=$(wildcard *.cpp)

CPP_FLAGS=-std=c++14

COMPILER=g++

DEBUG=-g

OUTPUT="-oout"

install:
	$(COMPILER) $(SOURCES) $(CPP_FLAGS) $(OUTPUT) $(DEBUG)
