TARGET = btox
CC = gcc
DEL = rm -rf 
SRC = $(wildcard src/*.c) $(wildcard src/*/*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET) 

$(TARGET): $(OBJ)
	echo $(OBJ)
	gcc $^ -o $(TARGET)

%.o: %.c 
	$(CC) -c $< -o $@ 

clean:
	$(DEL) $(OBJ)
	$(DEL) $(TARGET)
