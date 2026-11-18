CC = gcc
CFLAGS = -Wall -Wextra -O2
CIBLE1 = exo1
CIBLE2 = exo2

all: $(CIBLE1) $(CIBLE2)

$(CIBLE1): exo1.o tas_bin.o
	$(CC) $(CFLAGS) -o $@ $^

$(CIBLE2): exo2.o double_tas.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(CIBLE1) $(CIBLE2)
	