#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "libft.h"
#include <stdio.h>

#define PATH "input.txt"

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main()
{
	// Find space needed for the string
	int list1[1000] = {0};
	int list2[1000] = {0};
	int fd = open(PATH, O_RDONLY);
	char *line = get_next_line(fd);
	if (!line)
		return (1);
	int len = 0;
	while(line)
	{
		len += ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	get_next_line(-1);
	free(line);
	close(fd);
	// Fill list1 and list2 with all the values
	char *str = calloc(len + 1, sizeof(char));
	if (!str)
		return (1);
	fd = open(PATH, O_RDONLY);
	if (fd == -1)
		return (free(str), close(fd), 1);
	if (read(fd, str, len) < 0)
		return (free(str), close(fd), 1);
	close(fd);
	char *lim = " \n";
	char *token = 0;
	token = strtok(str, lim);
	list1[0] = ft_atoi(token);
	token = strtok(NULL, lim);
	if (!token)
		return (1);
	list2[0] = ft_atoi(token);
	int i = 1;
	while(i <= 999)
	{
		token = strtok(NULL, lim);
		if (!token)
			break;
		list1[i] = ft_atoi(token);
		token = strtok(NULL, lim);
		list2[i] = ft_atoi(token);
		i++;
	}
	free(str);
	// Sort list1 and list2
	qsort(list1, 1000, sizeof(int), compare);
	qsort(list2, 1000, sizeof(int), compare);
	// Calculate the answer
	int answer = 0;
	for (int i = 0; i < 1000; i++)
	{
		answer += abs(list2[i] - list1[i]);
	}
	printf("The answer is: %i\n", answer);

}