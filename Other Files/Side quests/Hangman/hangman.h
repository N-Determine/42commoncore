#ifndef HANGMAN_H
# define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <time.h>

#define TRIES 7

/**
 * @brief Prints the ASCII art representation of the hangman.
 * 
 * This function displays the hangman based on the number of failed attempts made by the player.
 * The ASCII art updates progressively with each incorrect guess, showing different parts of the
 * hangman figure depending on the number of fails (from 0 to 7).
 * 
 * @param fails The number of incorrect guesses made so far. This determines which parts of
 *              the hangman to display.
 * 
 * @return void This function does not return a value.
 */
void print_hangman(int fails);
/**
 * @brief Converts all characters in a string to lowercase.
 * 
 * This function iterates through each character of the input string and converts
 * any uppercase alphabetic characters (A-Z) to their lowercase counterparts (a-z).
 * Non-alphabetic characters remain unchanged.
 * 
 * @param str The string to be converted to lowercase. This string is modified in place.
 * 
 * @return The modified string with all characters converted to lowercase.
 */
char	 *make_lower(char *str);
/**
 * @brief Prints the word with every letter that has not been found replaced with an underscore.
 * 
 * This function outputs the word, replacing any unfound letters with underscores ('_') and
 * leaving spaces between the characters for clarity. It uses an array to check which letters
 * have been found so far.
 * 
 * @param letters An array indicating the status of each letter: 1 if found, 0 if not.
 * 
 * @param word The word the player is attempting to guess.
 * 
 * @return 1 if there are still letters to be found (i.e., the game is ongoing),
 *         0 if all letters have been found (i.e., the player has won).
 */
int print_str(int *letters, char *word);
/**
 * @brief Checks if the string consists only of alphabetic characters.
 * 
 * 
 * @param str The string to be checked.
 * 
 * @return 1 if the string contains only alphabetic characters,
 *         0 if it contains any non-alphabetic characters.
 */
int		str_isalpha(char *str);

/**
 * @brief Prints a random insult along with the provided word.
 * 
 * This function generates and displays a playful insult to the player,
 * indicating that the guessed word was obvious. The message format is
 * 
 * @param word The word that was guessed or revealed
 * 
 * @return void This function does not return a value.
 */
void 	print_insult(char *word);

#endif
