CC := g++
OBJS := $(wildcard src/*.cpp)
HEADERS := include
SDL2FLAGS != pkg-config SDL2 --libs --cflags
EXECUTABLE := app

# -mconsole to actually use SDL_Log
all:
	$(CC) $(OBJS) -I$(HEADERS) $(SDL2FLAGS) -mconsole -o $(EXECUTABLE)