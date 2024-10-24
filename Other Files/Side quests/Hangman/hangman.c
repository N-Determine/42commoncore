/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hangman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:56:51 by adeters           #+#    #+#             */
/*   Updated: 2024/10/24 21:41:32 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "hangman.h"

int 	TRIES = 7;
char	*DEFAULT_WORD_LIST = "Wordlists/bigger3.txt";

int main(int ac, char **av)
{
	if (ac > 3)
	{
		fprintf(stderr, "Please read the manual on how to run the program properly\n");
		return (1);
	}
	char *word = NULL;
	int i = 0;
	if (ac == 2)
	{
		if (!str_isalpha(av[1]))
		{
			fprintf(stderr, "Why can you not just follow the rules and use only letters for the word!?\n");
			return (1);
		}
		word = make_lower(av[1]);
	}
	if (ac == 3 || ac == 1)
	{
		int fd = 0;	
		if (ac == 3)
			fd = open(av[2], O_RDONLY);
		else
			fd = open(DEFAULT_WORD_LIST, O_RDONLY);
		if (fd < 0)
		{
			fprintf(stderr, "Wordlist could not be loaded. Use a real one!\n");
			return (1);
		}
		int lines_in_dic = 0;
		while ((word = get_next_line(fd)) != NULL)
		{
			lines_in_dic++;
			free(word);
		}
		close(fd);
		if (!lines_in_dic)
		{
			fprintf(stderr, "Something went horribly wrong while counting the amount of words in the wordlist\n");
			return (1);
		}
		if (ac == 3)
			fd = open(av[2], O_RDONLY);
		else
			fd = open(DEFAULT_WORD_LIST, O_RDONLY);
		if (fd < 0)
		{
			fprintf(stderr, "Wordlist could not be loaded. Use a real one!\n");
			return (1);
		}
		word = get_next_line(fd);
		srand(time(NULL));
		if (ac == 3 && strcmp(av[1], "-r") == 0)
		{
			int line = rand();
			while (word && i < line % lines_in_dic)
			{
				free(word);
				word = get_next_line(fd);
				i++;
			}
		}
		else if (ac == 3)
		{
			while (word && i < (atoi(av[1]) % lines_in_dic))
			{
				free(word);
				word = get_next_line(fd);
				i++;
			}
		}
		else
		{
			int line = rand();
			while (word && i < line % lines_in_dic)
			{
				free(word);
				word = get_next_line(fd);
				i++;
			}
		}
		if (!word)
		{
			fprintf(stderr, "Somehow there could be no word extracted from the wordlist\n");
			return (1);
		}
		if (word[strlen(word) - 1] == '\n')
			word[strlen(word) - 1] = '\0';
		close(fd);
		word = make_lower(word); // Just in case there is accidentally a capital letter in a wordlist
	}
	get_next_line(-1);
	if (!word)
	{
		fprintf(stderr, "Somehow there could be no word extracted from the wordlist\n");
		return (1);
	}
	int letters[26] = {0}; // Array that tracks all the letters the user has already tried
	int letter_in_word[26] = {0}; // Array that stores all letters from the word to be found
	char used_characters[78] = {0}; // String that displays the used characters
	int used_characters_index = 0; // The index of the used characters string (to print the next ones)
	int game_state = 1; // Become 0 if game is won and thus exits the game loop
	int input_state = 0; // Becomes 1 if the user input is invalid and keeps do-while loop going
	char *buff; // Temporary buffer for every new letter
	char character; // Character extrated from buff
	int turn = 0; // Number of turns
	int fails = 0; // Number of fails
	i = 0;
	while (word[i])
	{
		letter_in_word[word[i] - 'a'] = 1;
		i++;
	}
	system("clear");
	print_str(letters, word);
	printf("   Fails left: %i/%i\n", TRIES, TRIES);
	printf("\nUsed characters: \n");
	while(game_state && fails < TRIES)
	{
		if (TRIES == 7)
			print_hangman(fails);
		if (turn == 0)
		{
			printf("Please insert the first letter: "); fflush(stdout);
		}
		else
		{
			printf("Please insert the next letter: "); fflush(stdout);
		}
		do {
			input_state = 0;
			buff = get_next_line(0);
			if (!buff)
			{	
				fprintf(stderr, "Something went horribly wrong. We're sorry (It's not our fault)\n");
				return (free(word), 1);
			}
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
		if islower(buff[0])
			character = buff[0];
		else
			character = tolower(buff[0]);
		if (turn == 0)
		{
			used_characters[used_characters_index] = character;
			used_characters_index++;
		}
		else
		{
			used_characters[used_characters_index] = ',';
			used_characters[used_characters_index + 1] = ' ';
			used_characters[used_characters_index + 2] = character;
			used_characters_index += 3;
		}
		letters[character - 'a'] = 1;
		system("clear");
		if (letter_in_word[tolower(buff[0]) - 'a'] == 0)
			fails++;
		game_state = print_str(letters, word);
		printf("   Fails left: %i/%i\n", (TRIES - fails), TRIES);
		printf("\nUsed characters: %s\n", used_characters);
		turn++;
		free(buff);
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
		if (ac == 3 || ac == 1)
			free(word);
	}
	else
	{
		printf("\n\n\n");
		if (TRIES == 7)
			print_hangman(fails);
		print_insult(word);
		//printf("the word was actually \"%s\". Wasn't that obvious..\n\n\n\n", word);
		if (ac == 3 || ac == 1)
			free(word);
	}
	return (0);
}
