#include "so_long.h"
#include "get_next_line.h"

#include <string.h> // Replace strlen with ft_strlen!!


// Must only contain 1, 0, P, C & E (and ghosts in bonus)
// Lines must be equal size (Rectangle)
// Only 1s on outer layer
// P and E must be connected



// Easy to add ghost char in bonus
static int is_valid_char(char c)
{
	int valid; 

	valid = 0;
	if (c == 'C' || c == 'E' || c == 'P')
		valid = 1;
	if (c == '1' || c == '0')
		valid = 1;
	return (valid);
}

/**
 * @brief Removes the newline character (`\n`) from the end of a string, if present.
 *        This allows `count_lines` to function correctly regardless of whether the
 *        map file ends with a newline character.
 *
 * @param str The string from which to remove the newline character.
 * 
 * @return A pointer to the modified string with any trailing newline replaced by `\0`.
 */
char	*rid_of_nl(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
}

/**
 * @brief Counts the number of lines in the specified file using `get_next_line` and 
 *        verifies that all lines have the same length, ensuring the file content forms a rectangular map.
 *
 * @param filename The path to the file containing the map to be read.
 *
 * @return `Nr of Lines` - The total number of lines in the map if the function is successful.
 * 
 *         `-1` - If an error occurs during file operations or if the file is empty.
 * 
 *         `-2` - If the lines in the file have differing lengths, indicating the map is not rectangular.
 */
static int count_lines(char *filename)
{
	char	*current_line;
	int		fd;
	int		current_len;
	int		line_count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	current_line = get_next_line(fd);
	if (!current_line)
		return (-1);
	line_count = 1;
	current_len = strlen(rid_of_nl(current_line));
	while (current_line)
	{
		free(current_line);
		current_line = get_next_line(fd);
		if (current_line)
		{
			current_line = rid_of_nl(current_line);
			if (current_len != strlen(current_line))
				return (free(current_line), get_next_line(-1), close(fd), -2);
			line_count++;
		}
	}
	return (close(fd), line_count);
}

// Function that gets the map from a file into an array within the program
char	**import_map(char *filename)
{
	char	**map;
	int		lines;
	// Count number of lines and number of characters per line
	lines = count_lines(filename);
	if (lines == -1)
		return (NULL);
	if (lines == -2)
		return (NULL); // Also return error that map is not rectangular
	// Allocate memory for the first array dimension
	map = malloc(sizeof(char *) * lines);
	if (!map)
		return (NULL);

	// Basically recreate split but with get next line for every field of the list 
}
