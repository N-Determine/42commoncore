/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:52:39 by adeters           #+#    #+#             */
/*   Updated: 2024/12/30 17:51:03 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <wait.h>

// ENUMS
/**
 * @brief Enumerates error codes for use with the print_errors function.
 *
 * This enum provides meaningful identifiers for error conditions in the
 * program. The codes are 1-indexed to allow them to be used as return 
 * values in the `main` function.
 *
 * @note The 1-indexing ensures compatibility with standard conventions 
 * for error codes in command-line programs, where a `0` return value 
 * indicates success and non-zero values indicate errors.
 */
enum e_errors
{
	/**
	 * @brief Indicates that the program was used incorrectly.
	 *
	 * This error occurs when the program receives invalid input or arguments
	 * that do not match the expected format or requirements.
	 */
	USAGE = 1,
	/**
	 * @brief Indicates that the paths could not be loaded.
	 *
	 * This error occurs when the program fails to retrieve or parse the 
	 * required paths, such as environment variables or configuration data.
	 */
	PATHS = 2,
	/**
	 * @brief Indicates that the programm could not be accessed.
	 *
	 */
	ACCESS = 3,
	SPLIT = 4,
	MALLOC = 5,
	/**
	 * command not found
	 */
	NFOUND = 6,
};

// FUNCTIONS
// errors.c
/**
 * @brief Prints an error message to the stderr depeding on a code (from the
 * e_errors enum)
 */
int		print_errors(int code);

// free.c
void	ft_free_list(char **arr);

//path.c
/**
 * @brief Extracts and splits the system's PATH environment 
 * variable into an array of paths.
 *
 * This function searches through the provided environment variables 
 * for the `PATH` variable. Once located, it splits the value of the 
 * `PATH` variable into an array of strings using ':' as a delimiter.
 *
 * @param env A null-terminated array of strings representing the 
 * environment variables. Each entry is in the format `KEY=VALUE`.
 *
 * @return A null-terminated array of strings where each string represents
 * a path in the `PATH` variable. If the `PATH` variable is not found or if
 * memory allocation fails, `NULL` is returned.
 *
 * @note The caller is responsible for freeing the returned array and its
 * elements to prevent memory leaks.
 *
 */
char	**get_paths(const char **env);
/**
 * @brief Checks if the given program is accessible in any of the provided 
 * paths, with specified access mode.
 *
 * This function iterates through an array of paths, appending the program 
 * name to each path with a '/' separator, and checks if the resulting file 
 * satisfies the specified access mode. It uses the `access` system call to
 * perform the check.
 *
 * @param paths A null-terminated array of strings representing directories
 * to search.
 * @param prog  The program name to check for accessibility.
 * @param mode  The access mode to check for. Check the manual for the 
 * `access` system call to see valid options.
 *
 * @return 
 * - The `index` of the path in the `paths` array where the program is 
 * accessible with the given mode.
 * 
 * - `-1` if the program is not found in any of the paths, if the 
 * inputs are invalid, or if a memory allocation error occurs.
 *
 */
int		check_access(char **paths, char *prog, int mode);
/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * This function allocates memory for a new string that contains
 * the concatenation of `s1` and `s2`. Both input strings remain
 * unmodified. If either input is `NULL`, the function returns `NULL`.
 *
 * @param s1 The first input string.
 * @param s2 The second input string.
 *
 * @return A pointer to a newly allocated string containing the concatenated
 * result. Returns `NULL` if memory allocation fails or if any input is `NULL`.
 *
 * @note The caller is responsible for freeing the returned string to 
 * avoid memory leaks.
 *
 */
char	*allo_strcat(const char *s1, const char *s2);
/**
 * @brief Concatenates three strings into a newly allocated string.
 *
 * This function creates a new string that is the concatenation 
 * of `s1`, `s2`, and `s3`. It uses `allo_strcat` internally to perform
 * the concatenation in two steps. If any input is `NULL`, the function
 * returns `NULL`.
 *
 * @param s1 The first input string.
 * @param s2 The second input string.
 * @param s3 The third input string.
 *
 * @return A pointer to a newly allocated string containing the 
 * concatenated result. Returns `NULL` if memory allocation fails 
 * or if any input is `NULL`.
 *
 * @note The caller is responsible for freeing the returned string to prevent
 * memory leaks. This function also frees intermediate allocations in case of
 * failure.
 *
 */
char	*allo_trip_strcat(const char *s1, const char *s2, const char *s3);

#endif