#include <string.h>
#include <stdbool.h>

bool isOpener(char c)
{
    if (c == '(' || c == '[' || c == '{')
        return (true);
    return (false);
}

bool isCloser(char c)
{
    if (c == ')' || c == ']' || c == '}')
        return (true);
    return (false);
}

bool isCorrectBracket(char closer, char opener)
{
	if (opener == '(' && closer == ')')
		return (true);
	if (opener == '[' && closer == ']')
		return (true);
	if (opener == '{' && closer == '}')
		return (true);
	return (false);
}

bool isValid(char* s) 
{
    int size = 0;
    int openers = 0;
    int closers = 0;
    int i = 0;
    if (!s)
        return (false);
    size = strlen(s);
    if (size % 2 != 0)
        return (false);
    while (s[i])
    {
        if (isOpener(s[i]))
            openers++;
        if (isCloser(s[i]))
            closers++;
        i++;
    }
    if (closers != openers)
        return (false);
    i = 0;
    char stack[size];
    memset(&stack, 0, size);
    while (s[i])
    {
        if (isOpener(s[i]))
			stack[strlen(stack)] = s[i];
        if (isCloser(s[i]))
		{
			if (strlen(stack) == 0)
			{}
			else if (strlen(stack) > 0 && isCorrectBracket(s[i], stack[strlen(stack) - 1]) == false)
				return (false);
			else
				stack[strlen(stack) - 1] = '\0';
		}
		i++;
    }
	if (strlen(stack) != 0)
		return (false);
    return (true);
}

#include <stdio.h>

int main(void)
{
	char *str = "){";
	char *str2 = "[()]";
	char *str3 = "(}";
	printf("%d\n", isValid(str));
	printf("%d\n", isValid(str2));
	printf("%d\n", isValid(str3));
}