CC = gcc
INCDIRS = -I.
OPT = -O0
CFLAGS = -Wall -g $(INCDIRS) $(OPT)
LIBS =

SRCDIR   = src
BUILDDIR = build

MODULES = node list 
CFILES = $(SRCDIR)/main.c $(foreach module,$(MODULES),$(wildcard $(SRCDIR)/$(module)/*.c))
OBJECTS = $(patsubst %.c, $(BUILDDIR)/%.o, $(notdir $(CFILES)))
BINARY = $(BUILDDIR)/link_list

VPATH = $(dir $(CFILES))

.PHONY: all run clean debug

all: $(BINARY)

run: $(BINARY)
	$(BINARY)

$(BINARY): $(OBJECTS) | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BUILDDIR)/%.o: %.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $^

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)

debug: $(BINARY) 
	valgrind --leak-check=yes --track-origins=yes $(BINARY)

info:
	@echo "Source files: $(CFILES)"
	@echo "Object files: $(OBJECTS)"
	@echo "Moduel folders: $(MODULES)"
	@echo "VPATH:  $(VPATH)"

