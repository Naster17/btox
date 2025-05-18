TARGET = btox
CC = gcc
DEL = rm -rf

CFLAGS = -pedantic
INCLUDE = -I.
# for feature static libs paths and -ltoxcore ...
LIBS = -L. 

# dont forget to use src/ specialy to not touch other .c files in ./
SRC = $(wildcard src/*.c) $(wildcard src/*/*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET) 

$(TARGET): $(OBJ)
	echo $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $(TARGET)

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

clean:
	$(DEL) $(OBJ)
	$(DEL) $(TARGET)
