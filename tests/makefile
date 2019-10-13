LIBS+=-lgtest -lpthread

SRC+=$(wildcard ./src/*.cpp)

INC=-I/home/piotr/git-repos/googletest/googletest/include/

all:
	g++ main.cpp $(SRC) $(INC) $(LIBS) -std=c++14
