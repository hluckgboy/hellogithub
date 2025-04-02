CC = gcc
CFLAGS = -Wall -Werror -g
LDFLAGS = -lm
SRCDIR = src
BINDIR = bin
INCLUDEDIR = include
OBJS = $(patsubst $(SRCDIR)/%.c, %, $(wildcard $(SRCDIR)/*.c))

.PHONY: all clean

all: $(OBJS)
	@printf "\033[33mYou can find the compiled files in the $(BINDIR) directory.\033[0m\n"

$(OBJS): %: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -o $(BINDIR)/$@ $< $(LDFLAGS)
	@printf "\033[32mCompiling $< to $@\033[0m\n"

$(BINDIR):
	mkdir -p $(BINDIR)
	@printf "\033[34mCreating $(BINDIR) directory\033[0m\n"

clean:
	rm -rf $(BINDIR)
	@printf "\033[31mCleaning up the $(BINDIR) directory\033[0m\n"