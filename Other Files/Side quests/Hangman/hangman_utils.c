#include "hangman.h"

void print_hangman(int fails)
{
	printf("\n");
	printf("###########\n");
	printf("#  /      |\n");
	printf("# /       |\n");
	if (fails > 0)
		printf("#/       ()\n");
	else
		printf("#/\n");
	if (fails > 3)
		printf("#        /|\\\n");
	else if (fails > 2)
		printf("#         |\\\n");
	else if (fails > 1)
		printf("#         |\n");
	else
		printf("#\n");
	if (fails > 4)
		printf("#         |\n");
	else
		printf("#\n");
	if (fails > 6)
		printf("#        / \\\n");
	else if (fails > 5)
		printf("#        /  \n");
	else
		printf("#\n");
	printf("#\n");
	printf("#\n");
	printf("#################\n");
	printf("#################\n");
	printf("\n\n");
}

char	 *make_lower(char *str)
{
	int i = 0;
	while (str[i])
	{
		str[i] = tolower(str[i]);
		i++;
	}
	return (str);
}

int print_str(int *letters, char *word)
{
	printf("Word: "); fflush(stdout);
	int i = 0;
	int game_state = 0;
	while (word[i])
	{
		if (letters[word[i] - 'a'] == 0)
		{
			write(1, "_ ", 2);
			game_state = 1;
		}
		else
		{
			write(1, &word[i], 1);
			write(1, " ", 1);
		}
		i++;
	}
	return (game_state);
}

int		str_isalpha(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (!isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void 	print_insult(char *word)
{
	int number_of_insults = 3;
	int random = rand() % number_of_insults;
	if (random == 0)
		printf("The word was actually \"%s\". Wasn't that obvious..\n\n\n\n", word);
	if (random == 1)
		printf("Even a baby could have guessed that the word was \"%s\".\n\n\n\n", word);
	if (random == 2)
		printf("How could you not see that the word was \"%s\". Not the sharpest tool in the shed..\n\n\n\n", word);
}