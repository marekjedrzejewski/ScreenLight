OBJS = screenlight.cpp

CC = g++

COMPILER_FLAGS = 

LINKER_FLAGS = -lSDL2

OBJ_NAME = ScreenLight

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
