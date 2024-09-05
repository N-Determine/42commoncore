#include <stdlib.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;

    i = 0; 
    while (s1[i] && i < n)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    while (s2[i] && i < n)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}
/*
#include <stdio.h>

int main(void)
{
    char *s1 = "ABD";
    char *s2 = "ABC";
    printf("%i\n", ft_strncmp(s1, s2, 2));
}*/