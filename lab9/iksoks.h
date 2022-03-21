#pragma once

#define X 'x'
#define O 'o'
#define EMPTY ' '

typedef struct {
	char table[3][3];
	char turn;
	int count;
} State;

void init(State *s);

void print(State *s);

int moves(State *s, int *moves);

void make_move(State *s, int m);

void undo_move(State *s, int m);

int isfinal(State *s);

int perft(State *s);

int minimax(State *s);

