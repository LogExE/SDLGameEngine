CC := g++
OBJS := src/main.cpp
SDL2FLAGS != pkg-config SDL2 --libs --cflags
EXECUTABLE := app

# -mconsole to actually use SDL_Log
all:
	$(CC) $(OBJS) $(SDL2FLAGS) -mconsole -o $(EXECUTABLE)