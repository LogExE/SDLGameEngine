CC := g++
OBJS := src/main.cpp
SDL2FLAGS != pkg-config SDL2 --libs --cflags
EXECUTABLE := app

all:
	$(CC) $(OBJS) $(SDL2FLAGS) -o $(EXECUTABLE)