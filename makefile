CC = gcc
CFLAGS = -Wall -Wextra -O2
CIBLE = main

all: $(CIBLE)

$(CIBLE): exo1.o tas_bin.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(CIBLE)
	