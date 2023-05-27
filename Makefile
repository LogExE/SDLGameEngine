rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CC := g++
SOURCES := $(call rwildcard,src,*.cpp)
OBJS := $(SOURCES:.cpp=.o)
HEADERS := include
SDL2FLAGS != pkg-config SDL2 --libs --cflags
SDL2IMGFLAGS != pkg-config SDL2_image --libs --cflags --static
SDL2TTFFLAGS != pkg-config SDL2_ttf --libs --cflags --static
SDL2NETFLAGS != pkg-config SDL2_net --libs --cflags --static
HARFBUZZ != pkg-config harfbuzz --libs --cflags --static
EXECUTABLE := app
DEPS := $(OBJS:.o=.d)

all: $(SOURCES) $(EXECUTABLE)

# -mconsole to actually use SDL_Log
$(EXECUTABLE): $(OBJS)
	$(CC) $(OBJS) -static $(SDL2FLAGS) $(SDL2IMGFLAGS) $(SDL2TTFFLAGS) $(SDL2NETFLAGS) $(HARFBUZZ)  -mconsole -o $(EXECUTABLE)

.cpp.o:
	$(CC) -I$(HEADERS) -static -MMD -c $< -o $@

include $(DEPS)

$(DEPS): ;

clean:
	del $(subst /,\, $(OBJS))
	del $(subst /,\, $(DEPS))