#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>


ssize_t frame_proc_duration(clock_t start, clock_t end)
{
	printf("%zi", (end-start) / CLOCKS_PER_SEC * 1000000);
	return ((end - start) / CLOCKS_PER_SEC * 1000000);
}

int main(void)
{
	int i;
	clock_t start = clock();
	while (i < 1000000)
		i++;
	clock_t end = clock();
	ssize_t time = frame_proc_duration(start, end);
	printf("%zi", time);
}
