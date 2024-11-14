/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:33:41 by adeters           #+#    #+#             */
/*   Updated: 2024/11/14 19:55:00 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Converts a string to an integer.
 *
 * This function parses the initial portion of the string pointed to by @p nptr
 * and converts it to an integer, taking into account leading whitespace and an
 * optional sign. The conversion stops at the first non-numeric character after
 * the digits, if any. If the string does not contain any valid integer
 * representation, it returns 0.
 *
 * @param nptr A pointer to the string to be converted.
 * @return The converted integer from the string. If @p nptr is NULL or the
 * string does not start with a number, returns 0.
 *
 * @note The function does not check for integer overflow or underflow.
 *
 *
 * `int value = ft_atoi("  -123abc");` -> value will be -123
 *
 */
int					ft_atoi(const char *nptr);
/**
 * @brief Sets a memory block to zero.
 *
 * This function sets the first @p n bytes of the memory area pointed to by @p s
 * to zero (null bytes).
 *
 * @param s A pointer to the memory area to be zeroed. If @p s is `NULL`, the
 *          function does nothing.
 * @param n The number of bytes to set to zero.
 *
 * @note If @p n is 0, the function does nothing. This improved implementation
 *       ensures safe behavior when @p s is `NULL`, unlike the original `bzero`
 *       which would cause undefined behavior in that case.
 *
 * `ft_bzero(buffer, 10);` -> buffer is now filled with zeroes
 *
 * `ft_bzero(NULL, 5);` -> does nothing safely, avoiding undefined behavior
 */
void				ft_bzero(void *s, size_t n);
/**
 * @brief Allocates zero-initialized memory with overflow protection.
 *
 * This function allocates memory for an array of @p nmemb elements of @p size
 * bytes each and initializes all bytes to zero. It includes overflow protection
 * to prevent undefined behavior when the multiplication of @p nmemb and @p size
 * would exceed the maximum size_t value.
 *
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element.
 * @return A pointer to the allocated memory. If the allocation fails or an
 *         overflow is detected, returns `NULL`.
 *
 * @note This function improves upon the standard `calloc` by including an
 *       overflow check for @p nmemb and @p size, preventing allocation attempts
 *       that exceed the memory limit. Additionally, it uses `ft_bzero` to
 *       initialize memory to zero, ensuring safe handling of `NULL` pointers.
 *
 * `int *arr = (int *)ft_calloc(5, sizeof(int));` -> Allocates and zeroes
 * memory for 5 integers
 */
void				*ft_calloc(size_t nmemb, size_t size);
/**
 * @brief Checks if the given character @p c is an alphanumeric character,
 * meaning it is either a letter (uppercase or lowercase) or a digit.
 *
 * @param c The character to check.
 * @return Returns a non-zero value (8) if @p c is alphanumeric (i.e.,
	a letter or digit),
 * otherwise returns 0.
 *
 * Example:
 *
 * `ft_isalnum('a');` -> returns 8
 *
 * `ft_isalnum('$');` -> returns 0
 */
int					ft_isalnum(int c);
/**
 * @brief Checks if the given character @p c is an alphabetic character,
 * meaning it is either a lowercase or uppercase letter.
 *
 * @param c The character to check.
 * @return Returns a non-zero value (1024) if @p c is alphabetic (i.e.,
	a letter),
 * otherwise returns 0.
 *
 * Example:
 *
 * `ft_isalpha('a');` -> returns 1024
 *
 * `ft_isalpha('1');` -> returns 0
 */
int					ft_isalpha(int c);
/**
 * @brief Checks if the given character @p c is a valid ASCII character,
 * which means it falls within the range 0 to 127.
 *
 * @param c The character to check.
 * @return Returns 1 if @p c is an ASCII character (i.e.,
	within the range 0-127),
 *         otherwise returns 0.
 *
 * Example:
 *
 * `ft_isascii('A');` -> returns 1
 *
 * `ft_isascii(200);` -> returns 0
 */
int					ft_isascii(int c);
/**
 * @brief Checks if the given character @p c is a digit (i.e., a character
 * in the range '0' to '9').
 *
 * @param c The character to check.
 * @return Returns a non-zero value (2048) if @p c is a digit,
	otherwise returns 0.
 *
 * Example:
 *
 * `ft_isdigit('5');` -> returns 2048
 *
 * `ft_isdigit('a');` -> returns 0
 */
int					ft_isdigit(int c);
/**
 * @brief Checks if the given character @p c is a printable character,
 * meaning it falls within the ASCII range of printable characters (32 to 126,
	inclusive).
 *
 * @param c The character to check.
 * @return Returns a non-zero value (16384 if) @p c is printable,
	otherwise returns 0.
 *
 * Example:
 *
 * `ft_isprint('A');` -> returns 16384
 *
 * `ft_isprint('\n');` -> returns 0
 */
int					ft_isprint(int c);
/**
 * @brief Converts an integer to a string representation.
 *
 * This function converts the given integer @p n into a string. The function
 * handles both positive and negative numbers.
 *
 * @param n The integer to convert.
 * @return A pointer to a string representing the integer @p n. If memory
 *         allocation fails, returns `NULL`.
 * @note
 * The string must be freed by the caller using free().
 *
 * Example:
 *
 * `ft_itoa(123);` -> returns "123"
 *
 * `ft_itoa(0);` -> returns "0"
 */
// PUT THIS IN THE NORMAL MAKEFILE
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
// ENDBONUS
/**
 * @brief Locates the first occurrence of a character in memory.
 *

/**
 * @brief Locates the first occurrence of a character in memory.
 *
 * This function searches for the first occurrence of the byte 
 * @p c in the memory block pointed to by @p s, examining up to @p n bytes.
 * It returns a pointer to the matching byte or `NULL` if the character 
 * is not found within the specified range.
 *
 * @param s Pointer to the memory block to search.
 * @param c The character to search for.
 * @param n The number of bytes to search.
 * @return A pointer to the first occurrence of @p c in the memory block, 
 *         or `NULL` if the character is not found within the first @p n bytes.
 *
 * Example:
 * 
 * `ft_memchr(buffer, 'a', 10);` -> returns a pointer to the first 
 * occurrence of 'a' within the first 10 bytes of `buffer`.
 * 
 * `ft_memchr(buffer, 'z', 10);` -> returns `NULL` if 'z' is not 
 * found within the first 10 bytes of `buffer`.
 */
void				*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief Compares two memory blocks byte by byte.
 *
 * This function compares the first @p n bytes of the 
 * memory blocks pointed to by @p s1 and @p s2. 
 * It returns an integer less than, equal to, or greater than zero 
 * if the first @p n bytes of @p s1 are found to be less than,
 *  equal to, or greater 
 * than the first @p n bytes of @p s2, respectively.
 *
 * @param s1 Pointer to the first memory block.
 * @param s2 Pointer to the second memory block.
 * @param n The number of bytes to compare.
 * @return An integer:
 * 
 *         - `0` if the first @p n bytes of both memory blocks are equal,
 * 
 *         - A negative value if the first byte that 
 * differs in @p s1 is less than in @p s2,
 * 
 *         - A positive value if the first byte that 
 * differs in @p s1 is greater than in @p s2.
 *
 * @note This function does not check for `NULL` pointers. 
 * If either @p s1 or @p s2 is `NULL`, 
 *       the behavior is undefined.
 *
 * Example:
 * 
 * `buffer1 = "1";`
 * 
 * `buffer2 = "2";`
 * 
 * `ft_memcmp(buffer1, buffer2, 1);` -> returns a non-zero value, such as `-1`
 * 
 * (returns `s1_ptr[i] - s2_ptr[i]`)
 * 
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
int					ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
