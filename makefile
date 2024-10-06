BINARY = exec
BUILDIR = build
SRCDIR = src

CXX = g++
SDLFLAGS = -lSDL2 -lSDL2_image
DEPFLAGS = -MP -MD
CFLAGS = -Wall -Wextra $(SDLFLAGS) $(DEPFLAGS)
CPPFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES	= $(patsubst %.cpp, %.o, $(patsubst $(SRCDIR)/%, $(BUILDIR)/%, $(CPPFILES)))
DEPFILES = $(patsubst %.cpp, %.d, $(patsubst $(SRCDIR)/%, $(BUILDIR)/%, $(CPPFILES)))

all: clear $(BINARY) run
clear:
	clear
$(BINARY): $(OBJFILES)
	$(CXX) -o $@ $^ $(SDLFLAGS)

$(BUILDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJFILES) $(DEPFILES)

run:
	./$(BINARY)

-include $(DEPFILES)
