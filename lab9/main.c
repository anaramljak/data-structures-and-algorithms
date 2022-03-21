#include <stdio.h>
#include "iksoks.h"

void main()
{
	State s;
	init(&s);
	print(&s);

	int count = perft(&s);
	printf("%d\n", count);
}