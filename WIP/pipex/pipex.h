/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:52:39 by adeters           #+#    #+#             */
/*   Updated: 2024/12/17 15:01:38 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

// ENUMS
enum e_errors
{
	USAGE,
	PATHS,
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
char	**get_paths(char **env);
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