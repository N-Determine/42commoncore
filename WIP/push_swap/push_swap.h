/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:47:24 by adeters           #+#    #+#             */
/*   Updated: 2024/11/15 21:02:38 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/**
 * @brief Enumeration of all the operations within
 * push_swap
 */
enum e_operations
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

enum e_errors
{
	INT_OVERFLOW
};

/**
 * @brief Prints an operation to the stdout
 */
void	print_ops(int operation);
/**
 * @brief Prints errors to the stderr
 */
void	print_errors(int code);

#endif