#include <string.h>
#include <stdbool.h>

bool isValid(char *s, size_t len);

int lengthOfLongestSubstring(char* s) 
{
    size_t i = 0;
    size_t j = 0;
    size_t len = strlen(s);
    // Empty string results in a 0
    if (len == 0)
        return (0);
    while (len > 0)
    {
        i = 0;
        while (i <= j)
        {
            if (isValid(s + i, len))
                return len;
            i++;
        }
        j++;
        len--;
    }
    return (0);
}

// function to check if substring is valid
bool isValid(char *s, size_t len)
{
    int map[128] = {0};
    size_t i = 0;
    while(i < len)
    {
		if (map[s[i]] == 0)
            map[s[i]] = s[i];
        else
            return (false);
		i++;
    }
    return (true);
}

#include <stdio.h>

int main(void)
{
	char *s1 = "avwxyzABCD";
	printf("%i\n", lengthOfLongestSubstring(s1));
}