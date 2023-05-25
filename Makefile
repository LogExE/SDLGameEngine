rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CC := g++
OBJS := $(call rwildcard,src,*.cpp)
HEADERS := include
SDL2FLAGS != pkg-config SDL2 --libs --cflags
EXECUTABLE := app

# -mconsole to actually use SDL_Log
all:
	$(CC) $(OBJS) -I$(HEADERS) $(SDL2FLAGS) -mconsole -o $(EXECUTABLE)