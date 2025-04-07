CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
LDFLAGS = -lm
SRCDIR = src
INCLUDE_DIR = include
BINDIR = bin
OBJS = $(patsubst $(SRCDIR)/%.c, %, $(wildcard $(SRCDIR)/*.c))

.PHONY: all clean

all: $(OBJS)

$(OBJS): %: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $(BINDIR)/$@ $<

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR)