#include "iksoks.h"
#include <stdio.h>

void init(State *s) {
	for (int m = 0; m < 9; m++) {
		int x = m % 3;
		int y = m / 3;
		s->table[x][y] = EMPTY;
	}
	s->turn = X;
	s->count = 0;
}

void print(State *s) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			printf("%c|", s->table[x][y]);
		}
		printf("\n");
		printf("------");
		printf("\n");
	}
	printf("turn %c\n", s->turn);
}

int moves(State *s, int *moves) {
	int i = 0;
	for (int m = 0; m < 9; m++) {
		int x = m % 3;
		int y = m / 3;
		if (s->table[x][y] == EMPTY) {
			moves[i] = m;
			i++;
		}
	}
	return i;
}

void make_move(State *s, int m) {
	int x = m % 3;
	int y = m / 3;
	s->table[x][y] = s->turn;
	s->turn = (s->turn == X) ? O : X;
	s->count++;
}

void undo_move(State *s, int m) {
	int x = m % 3;
	int y = m / 3;
	s->table[x][y] = EMPTY;
	s->turn = (s->turn == X) ? O : X;
	s->count--;
}

int isfinal(State *s) {
	if (s->count == 9)
		return 1;
	for (int y = 0; y < 3; y++) {
		if (s->table[y][0] != EMPTY && s->table[y][0] == s->table[y][1] && s->table[y][1] == s->table[y][2])
			return 1;
		if (s->table[0][y] != EMPTY && s->table[0][y] == s->table[1][y] && s->table[1][y] == s->table[2][y])
			return 1;
	}

	if (s->table[1][1] != EMPTY && s->table[0][0] == s->table[1][1] && s->table[1][1] == s->table[2][2])
		return 1;
	if (s->table[1][1] != EMPTY && s->table[0][2] == s->table[1][1] && s->table[1][1] == s->table[2][0])
		return 1;

	return 0;
}

int perft(State *s) {
	if (isfinal(s))
		return 1;
	int totcnt = 0;
	int mlist[10];
	int mc = moves(s, mlist);
	for (int i = 0; i < mc; i++) {
		int m = mlist[i];
		make_move(s, m);
		int cnt = perft(s);
		undo_move(s, m);
		totcnt += cnt;
	}
	return 1 + totcnt;
}

int minimax(State *s) {
	int rezultat = isfinal(s);
	if (rezultat != 0)
		return rezultat;

	int mlist[10];
	int mc = moves(s, mlist);
	if (s->turn == X) {
		// max
		int maxv = -10000;
		for (int i = 0; i < mc; i++) {
			int m = mlist[i];
			make_move(s, m);
			int v = minimax(s);
			undo_move(s, m);
			if (v > maxv)
				maxv = v;
		}
		return maxv;
	}
	else {
		// min
		int minv = 10000;
		for (int i = 0; i < mc; i++) {
			int m = mlist[i];
			make_move(s, m);
			int v = minimax(s);
			undo_move(s, m);
			if (v < minv)
				minv = v;
		}
		return minv;
	}
}
