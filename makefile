BINARY = exec
BUILDIR = build
SRCDIR = src

CXX = gcc
SDLFLAGS = -lSDL2 -lSDL2_image
DEPFLAGS = -MP -MD
CFLAGS = -Wall -Wextra $(SDLFLAGS) $(DEPFLAGS)
CFILES = $(wildcard $(SRCDIR)/*.c)
OBJFILES	= $(patsubst %.c, %.o, $(patsubst $(SRCDIR)/%, $(BUILDIR)/%, $(CFILES)))
DEPFILES = $(patsubst %.c, %.d, $(patsubst $(SRCDIR)/%, $(BUILDIR)/%, $(CFILES)))

all: $(BINARY) run
$(BINARY): $(build) $(OBJFILES)
	$(CXX) -o $@ $^ $(SDLFLAGS)

build:
	mkdir build

$(BUILDIR)/%.o: $(SRCDIR)/%.c
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJFILES) $(DEPFILES)

run:
	./$(BINARY)

-include $(DEPFILES)

