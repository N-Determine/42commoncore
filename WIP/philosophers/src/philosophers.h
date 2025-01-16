/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:03:45 by adeters           #+#    #+#             */
/*   Updated: 2025/01/16 17:13:25 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// LIBRARIES
# include <sys/time.h>
# include <unistd.h>

// ENUMS
enum				e_errors
{
	/**
	* @brief The program was not executed correctly (e.g. faulty arguments)
	*/
	USAGE = 1,
	/**
	 * @brief gettimeofday function failed to execute
	 */
	GTOD = 2,
};

enum				e_actions
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

// STRUCTS
typedef struct s_data
{
	/**
		* @brief number_of_philosophers
		*
		* The number of philosophers and also the number of forks.
		*/
	int				nbp;
	/**
		* @brief  time_to_die (in milliseconds)
		*
		* If a philosopher didn’t start eating time_to_die milliseconds
		* since the beginning of their last meal or the beginning of
		* the simulation, they die.
		*/
	int				ttd;
	/**
		* @brief time_to_eat (in milliseconds)
		*
		* The time it takes for a philosopher to eat.
		*
		* During that time, they will need to hold two forks.
		*/
	int				tte;
	/**
		* @brief time_to_sleep (in milliseconds)
		*
		* The time a philosopher will spend sleeping.
		*/
	int				tts;
	/**
		* @brief number_of_times_each_philosopher_must_eat (optional argument)
		* If all philosophers have eaten at least
		* number_of_times_each_philosopher_must_eat times, the simulation stops.
		* If not specified, the simulation stops when a philosopher dies.
		*/
	int				nbte;
	int				error;
	struct timeval				start;
	struct timeval				curr;
	unsigned int				elapsed;
}					t_data;

typedef struct s_atoi_data
{
	int	sign;
	int	nmb;
	int	i;
}				t_atoi_data;

// FUNCTIONS
// helpers.c
int					ft_strlen(char *str);
void				p_nbr_fd(int fd, int n);
/**
 * @brief Converts a string to an integer.
 *
 * This function parses the initial portion of the string pointed to by @p nptr
 * and converts it to an integer, taking into account leading whitespace and an
 * optional sign. The conversion stops at the first non-numeric character after
 * the digits, if any. If the string does not contain any valid integer
 * representation, it returns -1.
 *
 * @param nptr A pointer to the string to be converted.
 * @return The converted integer from the string. If @p nptr is NULL or the
 * string does not start with a number, returns -1.
 *
 * @note The function does not check for integer overflow or underflow.
 *
 *
 * `int value = ft_atoi("  -123abc");` -> value will be -123
 *
 */
int					ft_atoi(const char *nptr);
unsigned int		time_passed(t_data *data);
// printer.c
/**
 * @brief Prints a string str to the file descriptor fd
 */
void				p_str_fd(int fd, char *str);
/**
 * @brief Prints a log for every action of any philosopher
 */
void				p_log(t_data *data, int philo_nb, int action);
int					p_err(int code);

#endif