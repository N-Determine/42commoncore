/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:47:24 by adeters           #+#    #+#             */
/*   Updated: 2024/11/28 14:41:50 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_fails
{
	size_t			underflows;
	size_t			overflows;
	size_t			formats;
	size_t			duplicates;
}					t_fails;

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
	int				nb;
	/**
		* @brief Pointer to the next node in the list.
		*
		* This points to the next `t_dlist` node in the linked list,
			or `NULL` if
		* this is the last node.
		*/
	struct s_dlist	*next;
	/**
		* @brief Pointer to the previous node in the list.
		*
		* This points to the next `t_dlist` node in the linked list,
			or `NULL` if
		* this is the first node.
		*/
	struct s_dlist	*pre;
}					t_dlist;

typedef struct s_stacks
{
	t_dlist			*stack_a;
	t_dlist			*stack_b;
	int				*sorted;
	int				len;
	int				nodes_stack_a;
	int				nodes_stack_b;
}					t_stacks;

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
		*  Any kind of error within the command-line arguments
		*/
	ARGS,
	/**
		* Error that has been caused by a failed malloc
		*/
	MAL,
	/**
	 * If the program was not correctly executed
	 */
	USAGE,
	/**
	 * The input string is not splittable
	 */
	SPLIT,
};
// print_ops.c
/**
 * @brief Prints an operation to the stdout
 */
void				print_ops(int operation);
// print_errors.c
/**
 * @brief Prints errors to the stderr. It also takes the t_fails
 * struct as an imput what allows it to print values in combination with
 * the errors (e.g. Amount of integer overflows etc.)
 */
void				print_errors_args(int code, t_fails *fails);
/**
 * @brief Prints errors to the stderr
 */
void				print_errors(int code);
// check_overflow.c
/**
 * @brief Determines if a string representation of a number
 * will overflow or underflow a 32-bit signed integer.
 *
 * This function evaluates whether converting a numeric string
 * to an integer using `ft_atoi()` would cause an overflow or
 * underflow of a 32-bit signed integer. It considers the maximum
 * and minimum values of `INT_MAX` (2147483647) and `INT_MIN` (-2147483648).
 *
 * The function accepts strings with optional `+` or `-` signs and ignores
 * leading zeros before the number. If the string is invalid (e.g., contains
 * no digits after the optional sign or zeros),
 * the function returns an error code.
 *
 * @param str The string containing the number to evaluate.
 * The string must be null-terminated and may include:
 *
 *            - An optional `+` or `-` as the first character.
 *
 *            - Leading zeros, which are ignored during evaluation.
 *
 * @return
 * - `0` if the number fits within the range of a 32-bit signed integer.
 *
 * - `-1` if the number would cause an underflow (less than `INT_MIN`).
 *
 * - `1` if the number would cause an overflow (greater than `INT_MAX`).
 *
 * - `-2` if the string is invalid (e.g., contains non-numeric
 * characters, or no digits after `+` or `-`).
 */
int					check_overflow(char *str);
// init.c
/**
 * @brief Initializes the t_fails struct so that functions that count
 * the amount of errors work properly (by setting errors counts to 0)
 */
void				init_fails(t_fails *fails);
// check_args.c
/**
 * @brief Validates command line arguments as integers and tracks errors.
 *
 * This function iterates through the provided command line arguments
 * to ensure each is a valid integer.
 * During validation, it identifies and counts specific types of errors,
 * including:
 *
 * - Overflow or underflow errors for integers outside the
 * range of a 32-bit signed integer.
 *
 * - Duplicate integers among the arguments.
 *
 * - Incorrectly formatted inputs (e.g., non-numeric characters
 * or empty strings).
 *
 * The error counts are stored in a `t_fails` structure, allowing detailed
 * diagnostics for pinpointing issues in the input.
 *
 * @param ac The argument count, including the program name.
 * @param av The argument vector, an array of strings representing
 * the command line arguments.
 * @param fails A pointer to a `t_fails` structure used to
 * record and track error types.
 *
 * @return
 * - `0` if all arguments are valid integers.
 *
 * - `1` if one or more arguments are invalid.
 *
 */
int					check_args(int ac, char **av, t_fails *fails);
// filling.c
/**
 * Allocates space for an array and a t_dlist struct to be filled
 * with every command-line argument as integers.
 */
int					fill_stacks(int ac, char **av, t_stacks *stacks,
						t_fails *fails, int str_in);
/**
 * @brief Cleanly frees every node within stack_a. It depends on the
 * nodes_stack_a counter in the t_stacks struct.
 */
void				clear_stack_a(t_stacks *stacks);
// ops_push.c
/**
 * @brief	Takes the first element at the top of `stack_b` and puts
 * it at the top of `stack_a`.
 *
 * Does nothing if `stack_b` is empty.
 */
void				push_a(t_stacks *stacks);
/**
 * @brief	Takes the first element at the top of `stack_a` and puts
 * it at the top of `stack_b`.
 *
 * Does nothing if `stack_a` is empty.
 */
void				push_b(t_stacks *stacks);
// ops_rotate.c
/**
 * @brief 	Shifts up all elements of `stack_a` by 1.
 * 			The first element becomes the last one.
 *
 * @param code Takes a code to indicate if the operation should be
 * printed to the stdout:
 *
 * - `1` if it should
 *
 * - `0`(or every other code) if it shouldn't
 */
void				rotate_a(t_stacks *stacks, int code);
/**
 * @brief	Shifts up all elements of `stack_b` by 1.
 *			The first element becomes the last one.
 *
 * @param code Takes a code to indicate if the operation should be
 * printed to the stdout:
 *
 * - `1` if it should
 *
 * - `0`(or every other code) if it shouldn't
 */
void				rotate_b(t_stacks *stacks, int code);
/**
 * @brief `rotate_a` and `rotate_b` at the same time.
 *
 * @note Always prints the operation to the stdout.
 */
void				rotate_r(t_stacks *stacks);
// ops_rrotate.c
/**
 * @brief	Shifts down all elements of `stack_a` by 1.
 * 			The last element becomes the first one.
 *
 * @param code Takes a code to indicate if the operation should be
 * printed to the stdout:
 *
 * - `1` if it should
 *
 * - `0`(or every other code) if it shouldn't
 */
void				rrotate_a(t_stacks *stacks, int code);
/**
 * @brief	Shifts down all elements of `stack_b` by 1.
 * 			The last element becomes the first one.
 *
 * @param code Takes a code to indicate if the operation should be
 * printed to the stdout:
 *
 * - `1` if it should
 *
 * - `0`(or every other code) if it shouldn't
 */
void				rrotate_b(t_stacks *stacks, int code);
/**
 * @brief `rrotate_a` and `rrotate_b` at the same time.
 *
 * @note Always prints the operation to the stdout.
 */
void				rrotate_r(t_stacks *stacks);
// ops_swap.c
/**
 * @brief Swaps the first 2 elements at the top of `stack_a`
 *
 * Does nothing if there is only one or no elements.
 *
 * @param code Takes a code to indicate if the operation should be
 * printed to the stdout:
 *
 * - `1` if it should
 *
 * - `0`(or every other code) if it shouldn't
 */
void				swap_a(t_stacks *stacks, int code);
/**
 * @brief  Swaps the first 2 elements at the top of `stack_b`
 *
 * Does nothing if there is only one or no elements.
 *
 * @param code Takes a code to indicate if the operation should be
 * printed to the stdout:
 *
 * - `1` if it should
 *
 * - `0`(or every other code) if it shouldn't
 */
void				swap_b(t_stacks *stacks, int code);
/**
 * @brief `swap_a` and `swap_b` at the same time.
 *
 * @note Always prints the operation to the stdout.
 */
void				swap_s(t_stacks *stacks);
// dlist.c
/**
 * @brief Iterates through a `t_dlist` and returns the last
 * node.
 */
t_dlist				*last_node(t_dlist *head);
/**
 * @brief Checks if a `t_dlist` is sorted in non-descending
 * order
 *
 * @return The function returns:
 *
 * - `0` if the list is not sorted
 *
 * - `1` if the list is sorted or if the list is equal to `NULL`
 */
int					is_sorted(t_dlist *head);
// direction.c
/**
 * @brief Checks if a number nb is within the range of int start 
 * and int end (inklusive)
 */
int					in_ran(int nb, int start, int end);
int					nb_pos_down(t_dlist *head, int n);
int					nb_pos_up(t_dlist *head, int n);
int					nb_pos_down_range(t_dlist *head, int start, int end);
int					nb_pos_up_range(t_dlist *head, int start, int end);

// TO DELETE AFTERWARDS +++ ALSO FROM THE MAKEFILE
// testing.c
/**
 * @brief Prints a whole `t_dlist` showing the "index" followed by 
 * it's value. It is great for testing the current state of a stack.
 */
void				print_list(t_dlist *stack);
/**
 * @brief It uses the push_swap function and prints the whole list after
 * sorting aswell as the number of inputs and operations to sort them.
 * 
 * It is designed to be easily replaced with the push_swap function
 * within the main function.
 */
void				test_push_swap(t_stacks *stacks);
// algorithms.c
int					push_swap(t_stacks *stacks);

#endif