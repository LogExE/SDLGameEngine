rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CC := g++
SOURCES := $(call rwildcard,src,*.cpp)
OBJS := $(SOURCES:.cpp=.o)
HEADERS := include
SDL2FLAGS != pkg-config SDL2 --libs --cflags
SDL2IMGFLAGS != pkg-config SDL2_image --libs --cflags
EXECUTABLE := app

all: $(SOURCES) $(EXECUTABLE)

# -mconsole to actually use SDL_Log
$(EXECUTABLE): $(OBJS)
	$(CC) $(OBJS) $(SDL2FLAGS) $(SDL2IMGFLAGS) -mconsole -o $(EXECUTABLE)

.cpp.o:
	$(CC) -I$(HEADERS) -c $< -o $@

clean:
	del $(subst /,\, $(OBJS))