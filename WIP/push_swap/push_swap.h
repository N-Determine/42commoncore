/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:47:24 by adeters           #+#    #+#             */
/*   Updated: 2024/11/16 17:40:01 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/**
 * @brief A node in a doubly linked list.
 *
 * This structure represents a single node in a doubly linked list, where each
 * node contains some integer data (`content`),
 * a pointer to the previous and one to the next node in the list.
 */
typedef struct s_dlist
{
	/**
		* @brief Pointer to the content of the node.
		*
		* This can point only to integers
		*/
	int				*nb;
	/**
		* @brief Pointer to the next node in the list.
		*
		* This points to the next `t_dlist` node in the linked list,
			or `NULL` if
		* this is the last node.
		*/
	struct s_list	*next;
	/**
		* @brief Pointer to the previous node in the list.
		*
		* This points to the next `t_dlist` node in the linked list,
			or `NULL` if
		* this is the first node.
		*/
	struct s_list	*pre;
}					t_dlist;

/**
 * @brief Enumeration of all the operations within
 * push_swap
 */
enum				e_operations
{
	/**
		* `swap a`
		*
		* Swap the first 2 elements at the top of stack a.
		* Do nothing if there is only one or no elements
		*/
	SA,
	/**
		* `swap b`
		*
		* Swap the first 2 elements at the top of stack b.
		* Do nothing if there is only one or no elements.
		*/
	SB,
	/**
		* `swap a` & `swap b` at the same time
		*/
	SS,
	/**
		* `push a`
		*
		*  Take the first element at the top of b and put it at the top of a.
		* 	Do nothing if b is empty
		*/
	PA,
	/**
		* `push b`
		*
		* Take the first element at the top of a and put it at the top of b.
		* Do nothing if a is empty.
		*/
	PB,
	/**
		* `rotate a`
		*
		* Shift up all elements of stack a by 1.
		* The first element becomes the last one.
		*/
	RA,
	/**
		* `rotate b`
		*
		* Shift up all elements of stack b by 1.
		* The first element becomes the last one.
		*/
	RB,
	/**
		* `rotate a` & `rotate b` at the same time
		*/
	RR,
	/**
		* `reverse rotate a`
		*
		*  Shift down all elements of stack a by 1.
		*  The last element becomes the first one.
		*/
	RRA,
	/**
		* `reverse rotate b`
		*
		* Shift down all elements of stack b by 1.
		* The last element becomes the first one.
		*/
	RRB,
	/**
		* `reverse rotate a` & `reverse rotate b` at the same time
		*/
	RRR,
};

enum				e_errors
{
	/**
		* Error that occured because of an overflowing integer
		*/
	INT_OVERFLOW,
	/**
		* Error that occured because of an underflowing integer
		*/
	INT_UNDERFLOW
};
// print_ops.c
/**
 * @brief Prints an operation to the stdout
 */
void				print_ops(int operation);
// print_errors.c
/**
 * @brief Prints errors to the stderr
 */
void				print_errors(int code);
// check_overflow.c
/**
 * @brief Determines if a string representation of a number will overflow 
 * or underflow a 32-bit signed integer.
 *
 * This function evaluates whether converting a numeric string to an 
 * integer using `ft_atoi()` would cause an overflow or underflow of a 32-bit 
 * signed integer. It considers the maximum and minimum values of 
 * `INT_MAX` (2147483647) and `INT_MIN` (-2147483648) during the check.
 *
 * @param str The string containing the number to evaluate. 
 * The string must be null-terminated.
 *
 * @return
 * - `0` if the number fits within the range of a 32-bit signed integer.
 * 
 * - `-1` if the number would cause an underflow (less than `INT_MIN`).
 * 
 * - `1` if the number would cause an overflow (greater than `INT_MAX`).
 *
 * @attention
 * The function assumes the input string is a valid numeric representation. 
 * It does not handle non-numeric characters or malformed inputs.
 *
 */
int					check_overflow(char *str);

#endif