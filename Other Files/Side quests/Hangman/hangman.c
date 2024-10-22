#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include "get_next_line.h"

// Global Variable Tries, no protection if the word has more than tries different letters (unless you can enter the whole word)
int TRIES = 11;

int print_str(int letters[26], char *str)
{
	printf("Word: "); fflush(stdout);
	int i = 0;
	int game_state = 0;
	while (str[i])
	{
		if (letters[str[i] - 'a'] == 0)
		{
			write(1, "_ ", 2);
			game_state = 1;
		}
		else
		{
			write(1, &str[i], 1);
			write(1, " ", 1);
		}
		i++;
	}
	return (game_state);
}
// make input upper lower case independent
// make it able to insert the full word
// make it able to use word from wordlist
int main(int ac, char **av)
{
	if (ac < 2 || ac > 3)
	{
		printf("Usage: ./a.out \"word to find\" OR ./a.out seed(random nr) wordlist\n");
		return (1);
	}
	char *word = NULL;
	int i = 0;
	if (ac == 2)
		word = av[1];
	if (ac == 3) // Needs more protections for valid inputs
	{
		int fd = open(av[2], O_RDONLY);
		int lines_in_dic = 0;
		while ((word = get_next_line(fd)) != NULL)
		{
			lines_in_dic++;
			free(word);
		}
		close(fd);
		fd = open(av[2], O_RDONLY);
		word = get_next_line(fd);
		while (word && i < (atoi(av[1]) % lines_in_dic))
		{
			free(word);
			word = get_next_line(fd);
			i++;
		}
		word[strlen(word) - 1] = '\0';
		close(fd);
	}
	get_next_line(-1);
	if (!word)
		return (1);
	int letters[26];
	int letter_in_word[26];
	char used_characters[78];
	int used_characters_index = 0;
	i = 0;
	while (i < 78)
	{
		used_characters[i] = 0;
		i++;
	}
	i = 0;
	while (i < 26)
	{
		letters[i] = 0;
		letter_in_word[i] = 0;
		i++;
	}
	i = 0;
	while (word[i])
	{
		letter_in_word[word[i] - 'a'] = 1;
		i++;
	}
	int game_state = 1;
	system("clear");
	print_str(letters, word);
	printf("   Tries left: %i\n", (TRIES));
	printf("\nUsed characters: %s\n", used_characters);
	int input_state = 0;
	char character;
	char *buff;
	int turn = 0;

	while(game_state && turn < TRIES)
	{
		if (turn == 0)
		{
			printf("\nPlease insert the first letter: "); fflush(stdout);
		}
		else
			printf("Please insert the next letter: "); fflush(stdout);
		do {
			input_state = 0;
			buff = get_next_line(0);
			// Check if the input is valid
			if (strlen(buff) != 2)
			{
				free(buff);
				printf("Try giving me a single character! "); fflush(stdout);
				input_state = 1;
			}
			else if (!isalpha(buff[0]))
			{
				free(buff);
				printf("Try a valid character from the english alphabet: "); fflush(stdout);
				input_state = 1;
			}
			else if (letters[tolower(buff[0]) - 'a'] == 1)
			{
				if (letter_in_word[tolower(buff[0]) - 'a'] == 1)
				{
					printf("This letter has already been found! Try another: "); fflush(stdout);
				}
				else
				{
					printf("You've tried this one and failed! Try again: "); fflush(stdout);
				}
				free(buff);
				input_state = 1;
			}
		} while (input_state == 1);
		// Make sure the character is always lower case
		if islower(buff[0])
			character = buff[0];
		else
			character = tolower(buff[0]);
		// First turn we do not need a Space and Comma between used letters
		if (turn == 0)
		{
			used_characters[used_characters_index] = character;
			used_characters_index++;
		}
		else // Then we do
		{
			used_characters[used_characters_index] = ',';
			used_characters[used_characters_index + 1] = ' ';
			used_characters[used_characters_index + 2] = character;
			used_characters_index += 3;
		}
		letters[character - 'a'] = 1; // Update the hashtable after letter is found
		system("clear"); 
		game_state = print_str(letters, word);
		printf("   Tries left: %i\n", (TRIES - turn - 1));
		printf("\nUsed characters: %s\n\n", used_characters);
		free(buff);
		turn++;
	}
	system("clear");
	get_next_line(-1);
	if (game_state == 0)
	{
		printf("YOU WIN! CONGRATULATIONS!\n");
		printf("\nTHE WORD WAS: *");
		i = 0;
		while (word[i])
		{
			printf("%c", toupper(word[i]));
			i++;
		}
		printf("*\n");
		if (ac == 3)
			free(word);
	}
	else
	{
		printf("\n\nthe word was actually \"%s\". Wasn't that obvious..\n\n\n\n", word);
		if (ac == 3)
			free(word);
	}
	return (0);
}
