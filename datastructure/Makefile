# filepath: /home/book/hellogithub/datastructure/Makefile

# Define the compiler to be used
CC = gcc

# Define the compiler flags: -Wall enables all warnings, -g adds debugging information
CFLAGS = -Wall -g

# Define the directory containing source files
SRCDIR = src

# Define the directory where compiled binary files will be stored
BINDIR = bin

# Define the directory containing header files
INCLUDEDIR = include

# Automatically generate a list of object files from source files
# $(patsubst ...) replaces the source file paths with corresponding binary file paths
OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%, $(wildcard $(SRCDIR)/*.c))

# Declare phony targets to avoid conflicts with files of the same name
.PHONY: all clean

# Default target: build all specified targets
all: $(OBJS)

# Rule to build each target program
# %: is a pattern matching wildcard that matches the target name (e.g., array, list, stack)
# $@ represents the target name, $< represents the first prerequisite
$(OBJS): %: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -o $(BINDIR)/$@ $<

# Rule to create the binary directory if it doesn't exist
$(BINDIR):
	mkdir -p $(BINDIR)

# Rule to clean up the binary directory
clean:
	rm -rf $(BINDIR)