#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif



char    *ft_strdup(char *str)
{
    char    *new;
    int        i;

    if (!str || !str)
        return (NULL);
    i = 0;
    while (str[i])
    {
        i++;
    }
    new = malloc(sizeof(char) * (i + 1));
    if (!new)
        return (NULL);
    i = 0;
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    *get_next_line(int fd)
{
    char        line[69000];
    static char    buf[BUFFER_SIZE];
    int            i;
    static int    rdb;
    static int    b_pos;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (b_pos >= rdb)
        {
            rdb = read(fd, buf, BUFFER_SIZE);
            b_pos = 0;
            if (rdb <= 0)
                break ;
        }
        line[i++] = buf[b_pos++];
        if (buf[b_pos] == '\n')
            break ;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}

int main(void)
{
	char *line = get_next_line(0);
	printf("%s\n", line);
	free(line);
}