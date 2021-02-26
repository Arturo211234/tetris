CC = gcc
CFLAGS = -O2 -march=native -Wall -Wextra -Wpedantic -std=c99
#CFLAGS = -g -march=native -Wall -Wextra -Wpedantic -std=c99
INFILE = main.c
OUTFILE = tetris

default:
	$(CC) $(CFLAGS) $(INFILE) -o $(OUTFILE)
