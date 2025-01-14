/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:52:39 by adeters           #+#    #+#             */
/*   Updated: 2025/01/14 18:57:21 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../src/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

// Limit of maximum pipes; changable at compile time
# ifndef FD_LIMIT
#  define FD_LIMIT 508
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
	 */
	USAGE = 1,
	/**
	 * @brief Indicates that the paths could not be loaded.
	 */
	PATHS = 2,
	/**
	 * @brief Indicates an error within the ft_split function
	 */
	SPLIT = 4,
	/**
	 * @brief Indicates an error while allocating space using malloc
	 */
	MALLOC = 5,
	/**
	 * @brief Indicates an error while executing the pipe function
	 */
	PIPE = 6,
	/**
	 * @brief Indicates an error while executing the fork function
	 */
	FORK = 7,
	/**
	 * @brief Indicates an error while executing the open function.
	 */
	OPEN = 8,
	/**
	 * @brief Indicates that too many fd are used. 
	 * 
	 * This means that the amount of commands require more pipes than
	 * can be opened by the defined FD_LIMIT that is defined within the
	 * pipex header (pipex.h)
	 */
	LIMIT = 9,
	/**
	 * @brief Indicates an error while executing the get_next_line function.
	 */
	GNL = 10,
	/**
	 * @brief Indicates an error while executing the execve function.
	 */
	EXEC = 11,
	/**
	 * dup2 function failed to execute
	 */
	DUP = 12,
	/**
	 * @brief Indicates that the permission for the program/file was denied
	 */
	PERM = 126,
	/**
	 * @brief Indicates that the programm could not be found.
	 *
	 */
	ACCESS = 127,
};

//	STRUCTS
/**
 * @brief Big structure that captures all necessary data and includes
 * all necessary variables withing the program.
 */
typedef struct s_data
{
	/**
	 * Array of possible paths in which an executable might be
	 */
	char	**paths;
	/**
	 * Array consisting of a executable name, optionally flags 
	 * and a terminating NULL
	 */
	char	**exe;
	/**
	 * Array of maximum possible concurrent processes (limited by
	 * FD_LIMIT)
	 */
	int		pid[FD_LIMIT + 1];
	/**
	 * Variable that is used in some functions passed by reference
	 * to set an error code when the return value is of another type.
	 * 
	 * Also used within the main function to return the proper exit
	 * status.
	 */
	int		error;
	/**
	 * 2D Array of maximum possible file descriptors (limited by 
	 * FD_LIMIT).
	 */
	int		fd[FD_LIMIT][2];
	/**
	 * File descriptor that is opened when the outfile is opened
	 */
	int		final_fd;
	/**
	 * File descriptor that is opened when the infile is opened
	 */
	int		init_fd;
	/**
	 * Variable that is passed by reference in the waitpid function
	 * to return the exit status of the last proccess
	 */
	int		wstatus;
	/**
	 * Amount of processes and therefore pipes needed to successfully
	 * use the program
	 */
	int		procs;
	/**
	 * Used to differentiate between the regular mode of reading
	 * from a file and the here_doc mode in which it reads from 
	 * the standart input. It will increase some indexes as the
	 * here_doc mode will always have one argument more (LIMITER)
	 */
	int		mode;
	/**
	 * Index variable used in the main function to loop through the
	 * mid_commands function
	 */
	int		index;
}	t_data;

// FUNCTIONS
// commands.c
int		first_command(t_data *data, const char **av);
int		first_help(t_data *data, const char **av);
int		mid_commands(t_data *data, const char **av, int i);
int		last_command(t_data *data, const char **av, int ac);
int		last_help(t_data *data, const char **av, int ac);

// errors.c
/**
 * @brief Prints an error message to the stderr depeding on a code (from the
 * e_errors enum)
 */
int		p_err(int code);
/**
 * @brief Prints an error message to the stderr depeding on a code (from the
 * e_errors enum). Also takes in an argument that can be printed out as well
 * (such as the command that caused the problem)
 */
int		p_err_arg(int code, const char *arg);

// free.c
/**
 * @brief Function that clears a 2D Array completely
 */
void	fr_lst(char **arr);
/**
 * @brief Function that clears all file descriptors that have been opened 
 * up within the programm
 * 
 * Takes the data structure containing the necessary data and the amount of 
 * pipes that have been opened before.
 */
void	fd_cl(t_data *data, int pipes_open);
/**
 * @brief Function that stops a process cleanly by exiting it with a code
 * that is given as an argument. It uses the fr_lst() and the fd_cl() function
 * to free any allocated space and close any previously opened file descriptor.
 */
int		stop_it(t_data *data, int err, const char *arg);

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
