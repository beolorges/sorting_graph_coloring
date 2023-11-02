CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Graph.o $(OBJ)/main.o $(OBJ)/SortingMethod.o $(OBJ)/Utils.o
HDRS = $(INC)/Graph.hpp $(INC)/SortingMethod.hpp $(INC)/Utils.hpp 
CFLAGS = -Wall -c -I $(INC) -pg

EXE = $(BIN)/tp2.out

all: $(OBJS)
	$(CC) -g -o $(EXE) $(OBJS) $(LIBS)	

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -g -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/Utils.o: $(HDRS) $(SRC)/Utils.cpp
	$(CC) $(CFLAGS) -g -o $(OBJ)/Utils.o $(SRC)/Utils.cpp 

$(OBJ)/SortingMethod.o: $(HDRS) $(SRC)/SortingMethod.cpp
	$(CC) $(CFLAGS) -g -o $(OBJ)/SortingMethod.o $(SRC)/SortingMethod.cpp 

$(OBJ)/Graph.o: $(HDRS) $(SRC)/Graph.cpp
	$(CC) $(CFLAGS) -g -o $(OBJ)/Graph.o $(SRC)/Graph.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out