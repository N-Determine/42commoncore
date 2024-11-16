#include "push_swap.h"

void init_fails(t_fails *fails)
{
	fails->underflows = 0;
	fails->overflows = 0;
	fails->formats = 0;
	fails->duplicates = 0;
}