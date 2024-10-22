#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
    // If all the first letters are the same, index = 0
    int i = 0;
    int j = 0;
    char *out = NULL;
    char c;

    while (strs[i][j])
    {
        // Check first letter of every word
        c = strs[i][j];
        while (i < strsSize - 1 && strs[i][j])
        {
            i++;
            if (strs[i][j] != c)
                break;
        }
        if (strs[i][j] != c)
                break;
        i = 0;
        j++;
    }
    out = malloc(j + 1);
    if (out == NULL)
        return (NULL);
    i = 0;
    while (i < j)
    {
        out[i] = strs[0][i];
        i++;
    }
    out[i] = '\0';
    return (out);
}

#include <stdio.h>

int main(void)
{
	char *strs[3] = {"hello", "hellouiu", "helloasdsd"};
	char *str = longestCommonPrefix(strs, 3);
	printf("%s\n", str);
	return (0);
}