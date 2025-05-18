TARGET = btox
CC = gcc
DEL = rm -rf

COLOR_MAKE=y

# -pedantic
CFLAGS =
INCLUDE = -I.
# for feature static libs paths and -ltoxcore ...
LIBS = -L. 

# dont forget to use src/ specialy to not touch other .c files in ./
SRC = $(wildcard src/*.c) $(wildcard src/*/*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET) 

$(TARGET): $(OBJ)
ifeq ($(COLOR_MAKE), y)
	@echo [LD] $(TARGET)
	@$(CC) $(CFLAGS) $(LIBS) $^ -o $(TARGET)
else
	$(CC) $(CFLAGS) $(LIBS) $^ -o $(TARGET)
endif

%.o: %.c
# ifeq and other is sensative to space use tab insted
ifeq ($(COLOR_MAKE), y)
	@echo [CC] $<
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 
else
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 
endif

clean:
ifeq ($(COLOR_MAKE), y)
	@echo [RM] $(OBJ)
	@echo [RM] $(TARGET)
	@$(DEL) $(OBJ)
	@$(DEL) $(TARGET)
else
	$(DEL) $(OBJ)
	$(DEL) $(TARGET)
endif
