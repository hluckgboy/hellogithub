CC = gcc
CFLAGS = -Wall -Werror -g
LDFLAGS = -lm
SRCDIR = src
BINDIR = bin
INCLUDEDIR = include
OBJS = $(patsubst $(SRCDIR)/%.c, %, $(wildcard $(SRCDIR)/*.c))

.PHONY: all clean

all:$(OBJS)

$(OBJS): %: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -o $(BINDIR)/$@ $<

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR)