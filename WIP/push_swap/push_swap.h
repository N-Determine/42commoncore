/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:47:24 by adeters           #+#    #+#             */
/*   Updated: 2024/11/30 17:25:40 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

// ENUMS
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

// Structs
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

typedef struct s_fails
{
	/**
	 * Keeps track of the amount of integer underflows
	 */
	size_t			underflows;
	/**
	 * Keeps track of the amount of integer overflows
	 */
	size_t			overflows;
	/**
	 * Keeps track of the amount of formatting errors
	 */
	size_t			formats;
	/**
	 * Keeps track of the amount of duplicates
	 */
	size_t			duplicates;
}					t_fails;

typedef struct s_stacks
{
	/**
	 * `stack_a` as a doubly linked list
	 */
	t_dlist			*stack_a;
	/**
	 * `stack_b` as a doubly linked list
	 */
	t_dlist			*stack_b;
	/**
	 * Array of all the input values sorted in ascending order
	 */
	int				*sorted;
	/**
	 * Amount of numbers in the initial `stack_a`
	 */
	int				len;
	/**
	 * Flag that is `1` if the values have been input
	 * as a single string and `0` if the values have 
	 * been input as individual command-line arguments.
	 * This is mainly needed to check if `av` needs to 
	 * be freed or not.
	 */
	int				str_in;
	/**
	 * Keeps track of the amount of nodes currently in
	 * `stack_a`
	 */
	int				nodes_stack_a;
	/**
	 * Keeps track of the amount of nodes currently in
	 * `stack_b`
	 */
	int				nodes_stack_b;
}					t_stacks;

// FUNCTIONS
// block_sort.c
int					block_sort(t_stacks *stacks, int divider);
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
// direction.c
/**
 * @brief Checks if a number is within a specified range.
 *
 * This function determines if a given number `nb` falls inclusively
 * within the range defined by `start` and `end`.
 *
 * @param nb The number to check.
 * @param start The start of the range (inclusive).
 * @param end The end of the range (inclusive).
 * @return 1 if `nb` is within the range `[start, end]`, otherwise 0.
 */
int					in_ran(int nb, int start, int end);
/**
 * @brief Finds the position of a number in a doubly linked list.
 *
 * This function iterates through a doubly linked list starting from `head` 
 * and counts the number of steps required to find the first occurrence of 
 * the given number `n`. If the number is not found, the total number of 
 * nodes in the list is returned.
 *
 * @param head A pointer to the head of the doubly linked list.
 * @param n The number to find in the list.
 * @return The number of steps (nodes) to reach the first occurrence of `n`. 
 *         If `n` is not found, the total node count is returned.
 */
int					nb_pos_down(t_dlist *head, int n);
/**
 * @brief Finds the position of a number in a doubly linked list, 
 * starting from the tail.
 *
 * This function iterates through a doubly linked list starting from the last
 * node and counts the number of steps required to find the first 
 * occurrence of the given number `n`. If the number is not found, 
 * the total number of nodes in the list is returned.
 *
 * @param head A pointer to the head of the doubly linked list.
 * @param n The number to find in the list.
 * @return The number of steps (nodes) to reach the first occurrence of `n`. 
 *         If `n` is not found, the total node count is returned.
 */
int					nb_pos_up(t_dlist *head, int n);
/**
 * @brief Finds the position of a number within a range in a doubly linked list.
 *
 * This function iterates through a doubly linked list starting from `head` 
 * and counts the number of steps required to find the first occurrence of 
 * a number within the range `[start, end]`. If no number in the range is found,
 * the total number of nodes in the list is returned.
 *
 * @param head A pointer to the head of the doubly linked list.
 * @param start The start of the range (inclusive).
 * @param end The end of the range (inclusive).
 * @return The number of steps (nodes) to reach the first occurrence of a number 
 *         in the range `[start, end]`. If no number in the range is found, 
 *         the total node count is returned.
 */
int					nb_pos_down_range(t_dlist *head, int start, int end);
/**
 * @brief Finds the position of a number within a range in a doubly linked list,
 * starting from the tail.
 *
 * This function iterates through a doubly linked list starting from the last
 * node and counts the number of steps required to find the first occurrence of
 * a number within the range `[start, end]`. If no number in the range is found,
 * the total number of nodes in the list is returned.
 *
 * @param head A pointer to the head of the doubly linked list.
 * @param start The start of the range (inclusive).
 * @param end The end of the range (inclusive).
 * @return The number of steps (nodes) to reach the first occurrence of a number 
 *         in the range `[start, end]`. If no number in the range is found, 
 *         the total node count is returned.
 */
int					nb_pos_up_range(t_dlist *head, int start, int end);
// dlist.c
/**
 * @brief Finds the last node in a doubly linked list.
 *
 * This function traverses a doubly linked list starting from `head` 
 * and returns a pointer to the last node in the list. If the list is empty,
 * the function returns `NULL`.
 *
 * @param head A pointer to the head of the doubly linked list.
 * @return A pointer to the last node in the list. If the list is empty, 
 * `NULL` is returned.
 */
t_dlist				*last_node(t_dlist *head);
/**
 * @brief Checks if a doubly linked list is sorted in ascending order.
 *
 * This function iterates through a doubly linked list starting from `head` 
 * and checks whether all the elements are sorted in ascending order. 
 * If the list is empty or sorted, the function returns `1`. Otherwise, 
 * it returns `0`.
 *
 * @param head A pointer to the head of the doubly linked list.
 * @return `1` if the list is empty or sorted in ascending order, otherwise `0`.
 */
int					is_sorted(t_dlist *head);
/**
 * @brief Finds the largest number in a doubly linked list.
 *
 * This function iterates through a doubly linked list starting from `head` 
 * and finds the largest number among the nodes. If the list is empty, 
 * the function returns `0`.
 *
 * @param head A pointer to the head of the doubly linked list.
 * @return The largest number in the list. If the list is empty, returns `0`.
 */
int					find_biggest(t_dlist *head);
/**
 * @brief Finds the smallest number in a doubly linked list.
 *
 * This function iterates through a doubly linked list starting from `head` 
 * and finds the smallest number among the nodes. If the list is empty, 
 * the function returns `0`.
 *
 * @param head A pointer to the head of the doubly linked list.
 * @return The smallest number in the list. If the list is empty, returns `0`.
 */
int					find_smallest(t_dlist *head);
// filling.c
/**
 * Allocates space for an array and a t_dlist struct to be filled
 * with every command-line argument as integers.
 */
int					fill_stacks(int ac, char **av, t_stacks *stacks,
						t_fails *fails);
/**
 * @brief Cleanly frees every node within stack_a. It depends on the
 * nodes_stack_a counter in the t_stacks struct.
 */
void				clear_stack_a(t_stacks *stacks);
// init.c
/**
 * @brief Initializes the t_fails struct so that functions that count
 * the amount of errors work properly (by setting errors counts to 0)
 */
void				init_fails(t_fails *fails);
// main_helpers.c
/**
 * @brief Checks if a string represents a valid number.
 *
 * This function iterates through each character of the input string `str`
 * and checks whether each character is a digit, or a plus (`+`) 
 * or minus (`-`) sign. If all characters are valid, it returns `1`. 
 * If any character is invalid, it returns `0`.
 *
 * @param str A pointer to the string to check.
 * @return `1` if the string represents a valid number, otherwise `0`.
 */
int					ft_isdigit_str(char *str);
/**
 * @brief Counts the number of elements in the modified `char **av`
 * from the input. Basically updates `int ac` in case that the 
 * values were given as a single string instead of individual
 * command-line arguments.
 *
 * @param arr A pointer to the array of strings.
 * @return The number of elements in the array (excluding `NULL`).
 */
int					new_count(char **arr);
/**
 * @brief Frees all dynamically allocated memory for the array and stack.
 *
 * This function frees each string in the array `arr` (up to `stacks->len`), 
 * then frees the array itself. It only performs these actions if the `str_in` 
 * field in `stacks` is not `NULL` and if `stacks->len` is greater than zero.
 *
 * @param arr A pointer to the array of strings to be freed.
 * @param stacks A pointer to the `t_stacks` structure that contains 
 * information about the array length.
 */
void				ft_free_all(char **arr, t_stacks *stacks);
/**
 * @brief Checks if a single command-line argument is a valid number.
 *
 * This function verifies if a single input provided as a command-line argument
 * can be considered a valid number, allowing for optional leading zeros, 
 * and a plus (`+`) or minus (`-`) sign. If the input is invalid, it prints 
 * an appropriate error message. If the input is valid, the function 
 * returns `0`,indicating successful validation and completion.
 *
 * @param ac The argument count passed to the program.
 * @param av The argument vector containing the command-line arguments.
 * @param fails A pointer to the `t_fails` 
 * structure that stores error information.
 * @return `1` if the input is invalid
 * 
 * `0` if the input is valid.
 */
int					check_single_str(int ac, char **av, t_fails *fails);
/**
 * @brief Converts a single input string into an array of command-line arguments.
 *
 * This function takes a single string input (e.g., a series of values separated 
 * by spaces) and splits it into an array of strings, mimicking the command-line 
 * argument format. The resulting array is used by the program as if the values 
 * were given as individual command-line arguments. It also updates the argument 
 * count (`ac`) using the `new_count()` fuction and stores relevant information 
 * in the `stacks` structure. If an error occurs during splitting or 
 * memory allocation, an error message is printed.
 *
 * @param input The input string containing values separated by spaces.
 * @param ac A pointer to the argument count, which will be 
 * updated with the number of elements.
 * @param stacks A pointer to the `t_stacks` structure, where the 
 * length of the new array and status are stored.
 * @return A pointer to the newly created array of strings 
 * (command-line arguments), or `NULL` if an error occurs.
 */
char				**new_av_maker(char *input, int *ac, t_stacks *stacks);
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
// print_ops.c
/**
 * @brief Prints an operation to the stdout
 */
void				print_ops(int operation);
// push_swap.c
/**
 * @brief Chooses the right algorithm based on the amount of numbers
 * that need to be sorted
 */
int					push_swap(t_stacks *stacks);

#endif