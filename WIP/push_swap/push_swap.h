/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:47:24 by adeters           #+#    #+#             */
/*   Updated: 2024/11/15 20:47:30 by adeters          ###   ########.fr       */
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
	 */
	SA,
	/**
	 * `swap b`
	 */
	SB,
	/**
	 * `swap a` & `swap b` at the same time
	 */
	SS,
	/**
	 * `push a`
	 */
	PA,
	/**
	 * `push n`
	 */
	PB,
	/**
	 * `rotate a`
	 */
	RA,
	/**
	 * `rotate b`
	 */
	RB,
	/**
	 * `rotate a` & `rotate b` at the same time
	 */
	RR,
	/**
	 * `reverse rotate a`
	 */
	RRA,
	/**
	 * `reverse rotate b`
	 */
	RRB,
	/**
	 * `reverse rotate a` & `reverse rotate b` at the same time
	 */
	RRR,
};

#endif