/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:52:39 by adeters           #+#    #+#             */
/*   Updated: 2025/01/13 19:17:02 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

// Limit of maximum pipes; changable at compile time
# ifndef FD_LIMIT
#  define FD_LIMIT 510
# endif

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
	 * @brief Indicates that the programm could not be found.
	 *
	 */
	ACCESS = 127,
	/**
	 * @brief Indicates that the permission for the program was denied
	 *
	 */
	PERM = 126,
	SPLIT = 4,
	MALLOC = 5,
	/**
	 * command not found
	 */
	NFOUND = 6,
	PIPE = 7,
	FORK = 8,
	OPEN = 9,
	LIMIT = 10,
	/**
	 * get_next_line function failed during here_doc
	 */
	GNL = 11,
	EXEC = 12,
};

//	STRUCTS
typedef struct s_data
{
	char	**paths;
	char	**exe;
	int		pid[FD_LIMIT + 1];
	int		error;
	int		fd[FD_LIMIT][2];
	int		final_fd;
	int		init_fd;
	int		wstatus;
	int		mode;
	int		code;
	int		procs;
	int		index;
}	t_data;

// FUNCTIONS
// commands.c
int		first_command(t_data *data, const char **av);
int		mid_commands(t_data *data, const char **av, int i);
int		last_command(t_data *data, const char **av, int ac);

// errors.c
/**
 * @brief Prints an error message to the stderr depeding on a code (from the
 * e_errors enum)
 */
int		p_err(int code);
int		p_err_arg(int code, const char *arg);

// free.c
void	fr_lst(char **arr);
void	fd_cl(t_data *data, int pipes_open);

// helpers.c
/**
 * Determines the write mode for the file at the end of the command chain.
 * 
 * This function is used to select the appropriate mode for writing to a file.
 * It supports two modes:
 * 
 * `code = 0`: Overwrites the file (uses `O_TRUNC`).
 * 
 * `code = 1`: Appends to the file (used for the here_doc in the bonus, 
 * with `O_APPEND`).
 * 
 * @param code An integer indicating the desired mode:
 * 
 * - `0`: Normal mode (overwrite).
 * 
 * - `1`: Append mode.
 * 
 * @return The appropriate flags for the `open` system call:
 * 
 * - `O_WRONLY | O_CREAT | O_TRUNC` for normal mode.
 * 
 * - `O_WRONLY | O_CREAT | O_APPEND` for append mode.
 */
int		write_mode(int code);
int		wait_all(t_data *data, int processes);
int		ft_strcmp(const char *s1, const char *s2);

// init.c
int		init_prog(t_data *data, int ac, const char **av, const char **env);
char	**mk_exe(char **paths, const char *arg, int *error);
int		pipe_maker(t_data *data, int pipes_amt);
char	*make_limiter(const char **av);
int		get_here_doc(t_data *data, const char **av);

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
 *
 * @return 
 * - The `index` of the path in the `paths` array where the program is 
 * accessible with the given mode.
 * 
 * - `-1` if the program is not found in any of the paths, if the 
 * inputs are invalid, or if a memory allocation error occurs.
 *
 */
int		check_access(char **paths, char *prog);
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
