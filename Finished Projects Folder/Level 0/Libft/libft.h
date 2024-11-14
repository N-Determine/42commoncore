/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:33:41 by adeters           #+#    #+#             */
/*   Updated: 2024/11/14 22:12:01 by adeters          ###   ########.fr       */
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
/**
 * @brief *UNSAFE* - Use ft_memmove instead! 
 * 
 * Copies memory from one block to another.
 *
 * This function copies @p n bytes from the memory area pointed to by 
 * @p src to the memory area pointed to by @p dest.
 *
 * @param dest Pointer to the destination memory 
 * block where the content will be copied.
 * @param src Pointer to the source memory 
 * block from which the content will be copied.
 * @param n The number of bytes to copy from `src` to `dest`.
 * @return A pointer to the destination memory block @p dest, 
 * or `NULL` if either @p dest or @p src is `NULL`.
 *
 * @note The memory areas must not overlap.  Use ft_memmove 
 * if the memory areas do overlap.
 *
 * Example:
 * 
 * `ft_memcpy(buffer1, buffer2, 10);` -> copies the first 
 * 10 bytes from `buffer2` to `buffer1`.
 * 
 * `ft_memcpy(buffer1, NULL, 10);` -> returns `NULL` 
 * because the source pointer is `NULL`.
 */
void				*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @brief Copies memory from one block to another, 
 * handling overlapping memory regions.
 *
 * This function copies @p n bytes from the memory area 
 * pointed to by @p src to the memory area pointed to by @p dest. 
 * If the memory areas overlap, the function ensures that the copy 
 * is done correctly by copying the data in reverse order when the 
 * destination is located before the source.
 *
 * @param dest Pointer to the destination memory 
 * block where the content will be copied.
 * @param src Pointer to the source memory 
 * block from which the content will be copied.
 * @param n The number of bytes to copy from @p src to @p dest.
 * @return A pointer to the destination memory block @p dest, 
 * or `NULL` if either @p dest or @p src is `NULL`.
 *
 * Example:
 * 
 * `ft_memmove(buffer1, buffer2, 10);` -> 
 * copies first 10 bytes from `buffer2` to `buffer1`.
 * 
 * `ft_memmove(buffer1, NULL, 10);` -> 
 * returns `NULL` because the source pointer is `NULL`.
 * 
 * `ft_memmove(buffer1, buffer1 + 5, 5);` -> 
 * successfully handles overlapping memory (by copying data in reverse order).
 */
void				*ft_memmove(void *dest, const void *src, size_t n);
/**
 * @brief Sets the first @p n bytes of the memory area pointed to 
 * by @p s to the specified value.
 *
 * @param s Pointer to the memory block that will be set.
 * @param c The value to set. The value is passed as an `int`, 
 * but it is internally converted to an `unsigned char`.
 * @param n The number of bytes to set in the memory block.
 * @return A pointer to the memory block @p s, or `NULL` if @p s is `NULL`.
 *
 * Example:
 * 
 * `ft_memset(buffer, 65, 10);` -> sets the first 
 * 10 bytes of `buffer` to the value `65` (ASCII 'A').
 * 
 * `ft_memset(NULL, 65, 10);` -> returns `NULL` 
 * because the pointer is `NULL`.
 */
void				*ft_memset(void *s, int c, size_t n);
/**
 * @brief Writes the character @p c to the file descriptor @p fd.
 * It uses the `write` system call to perform the operation. 
 * If @p fd is invalid or the character cannot be written, 
 * the behavior is undefined.
 *
 * @param c The character to be written to the file descriptor.
 * @param fd The file descriptor where the character will be written. 
 * It can represent standard output, standard error, or any other open file.
 *
 * Example:
 * 
 * `ft_putchar_fd('A', 1);` -> writes the character 'A' 
 * to the standard output (file descriptor 1).
 * 
 * `ft_putchar_fd('B', 2);` -> writes the character 'B' 
 * to the standard error (file descriptor 2).
 */
void				ft_putchar_fd(char c, int fd);
/**
 * @brief Writes a string followed by a newline to a file descriptor.
 *
 * This function writes the string @p s to the file descriptor @p fd, 
 * followed by a newline character. It uses the `write` system call 
 * to perform the operation. If @p s is `NULL`, nothing is written, 
 * but the newline character will still be written to the file descriptor.
 *
 * @param s The string to be written to the file descriptor. 
 * It must be null-terminated.
 * @param fd The file descriptor where the string and newline will be written.
 * It can represent standard output, standard error, or any other open file.
 *
 * Example:
 * 
 * `ft_putendl_fd("Hello, world!", 1);` -> writes "Hello, world!" 
 * followed by a newline to the standard output.
 * 
 * `ft_putendl_fd(NULL, 1);` -> writes only a newline to the standard output.
 */
void				ft_putendl_fd(char *s, int fd);
/**
 * @brief Writes an integer to a file descriptor.
 *
 * This function writes the integer @p n to the file descriptor @p fd. 
 * It handles both positive and negative integers, 
 * writing a minus sign before a negative number.
 *
 * @param n The integer to be written to the file descriptor.
 * @param fd The file descriptor where the integer will be written. 
 * It can represent standard output, standard error, or any other open file.
 *
 * Example:
 * 
 * `ft_putnbr_fd(42, 1);` -> writes the integer 42 to the standard output.
 * 
 * `ft_putnbr_fd(-42, 2);` -> writes the integer -42 to the standard error.
 */
void				ft_putnbr_fd(int n, int fd);
/**
 * @brief Writes a string to a file descriptor.
 *
 * This function writes the string @p s to the file descriptor @p fd. 
 * It uses the `write` system call to perform the operation. 
 * If @p s is `NULL`, nothing is written.
 *
 * @param s The string to be written to the file descriptor. 
 * It must be null-terminated.
 * @param fd The file descriptor where the string will be written.
 * It can represent standard output, standard error, or any other open file.
 *
 * Example:
 * 
 * `ft_putstr_fd("Hello, world!", 1);` -> writes "Hello, world!" 
 * followed by a newline to the standard output.
 * 
 */
void				ft_putstr_fd(char *s, int fd);
/**
 * @brief Splits a string into an array of strings based on a delimiter.
 *
 * This function splits the given string @p s into an array of substrings, 
 * where each substring is delimited by the character @p c. 
 * The resulting array of strings is dynamically allocated, 
 * and the function returns a pointer to this array. 
 * The array will be terminated by a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character used to split the string.
 *
 * @return A pointer to an array of strings, or NULL if memory 
 * allocation fails or if the input string is empty.
 * 
 * @note The 2D Array must be properly freed using free() 
 * on every arr[n] (in a loop with the condition arr[n] != NULL) 
 * and the array arr itself.
 *
 * Example:
 * 
 * `char **result = ft_split("hello world", ' ');`
 * The result will be an array containing the strings 
 * "hello" and "world", terminated by NULL.
 * 
 */
char				**ft_split(char const *s, char c);
/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence 
 * of the character @p c in the string @p s.
 * If the character is found, it returns a pointer 
 * to the first occurrence of the character.
 * If the character is not found, it returns NULL.
 *
 * @param s The string to be searched.
 * @param c The character to search for in the string.
 *
 * @return A pointer to the first occurrence of the character 
 * in the string, or NULL if the character is not found.
 *
 * Example:
 * 
 * `char *result = ft_strchr("hello world", 'o');` ->
 * The result will point to the first occurrence of 'o' in "hello world".
 */
char				*ft_strchr(const char *s, int c);
/**
 * @brief Duplicates a string by allocating memory and copying its content.
 *
 * This function allocates memory for a new string 
 * and copies the content of the string @p s into it.
 * The new string is null-terminated. 
 * If memory allocation fails, the function returns NULL.
 * If @p s is NULL, the function will also return NULL.
 *
 * @param s The string to duplicate.
 *
 * @return A pointer to the newly allocated string that 
 * contains a duplicate of @p s, or NULL if memory allocation fails 
 * or if @p s is NULL.
 * 
 * @note The string duplicate has to be freed using free().
 *
 * Example:
 * 
 * `char *duplicate = ft_strdup("hello");` ->
 * The result will be a new string `duplicate` containing "hello".
 */
char				*ft_strdup(const char *s);
/**
 * @brief Applies a function to each character of a string.
 *
 * This function iterates over each character in the string @p s 
 * and applies the function @p f to each character. 
 * The function @p f is called with two arguments:
 * 
 * - the index of the character (starting from 0)
 * 
 * - a pointer to the character. 
 * 
 * If @p s is NULL, the function does nothing.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character of the string. 
 * The function should take two parameters: an unsigned int (the index) 
 * and a pointer to the character.
 *
 *
 * Example:
 * 
 * `char str[] = "hello";` 
 * 
 * `ft_striteri(str, to_uppercase);` 
 * -> After this, str will be "HELLO"
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * This function allocates memory for a new string that is 
 * the concatenation of @p s1 and @p s2. 
 * If @p s1 is NULL, the function returns NULL. 
 * If @p s2 is NULL, the function returns a copy of @p s1. 
 * After concatenation, the newly allocated string is returned.
 *
 * @param s1 The first string to concatenate. 
 * If NULL, the function returns NULL.
 * @param s2 The second string to concatenate. 
 * If NULL, a copy of @p s1 is returned.
 *
 * @return A new string that is the concatenation 
 * of @p s1 and @p s2, or NULL if allocation fails.
 *
 * @note The caller is responsible for 
 * freeing the returned string using `free()`.
 *
 * Example:
 * 
 * `char *result = ft_strjoin("Hello, ", "world!");`
 *  -> result contains "Hello, world!"
 */
char				*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief Appends the source string to the destination 
 * string up to a given buffer size.
 *
 * This function appends the string @p src to the end of @p dst. 
 * It appends at most `size - strlen(dst) - 1` characters and 
 * ensures the result is null-terminated. The function returns the 
 * initial length of @p dst plus the length of @p src.
 *
 * If the buffer size `size` is less than or equal to the length of @p dst, 
 * the function returns the length of @p src 
 * plus `size` without appending any characters.
 *
 * @param dst The destination string buffer. 
 * It should be large enough to hold the concatenated 
 * result up to the specified @p size.
 * @param src The source string to append to @p dst.
 * @param size The full size of the buffer that @p dst can use, 
 * including the null-terminator.
 *
 * @return The total length of the string that would have been created, that is, 
 * the initial length of @p dst plus the length of @p src. 
 * 
 * If @p dst or @p src are `ǸULL` the function returns `-1`
 *
 * @note If the function returns a value greater 
 * than or equal to @p size, truncation occurred.
 *
 * Example:
 * 
 * `char buffer[20] = "Hello, ";`
 * 
 * `size_t result = ft_strlcat(buffer, "world!", sizeof(buffer));` 
 * 
 * -> buffer now contains "Hello, world!" 
 * 
 * -> result is the total length of "Hello, world!" 
 * if it had fit without truncation
 */
size_t				ft_strlcat(char *dst, const char *src, size_t size);
/**
 * @brief Copies up to @p size - 1 characters from 
 * the string @p src to @p dest, ensuring null-termination of the result.
 *
 * This function copies characters from the source string @p src to the 
 * destination buffer @p dest, up to a maximum of `size - 1` characters, 
 * and appends a null-terminator at the end of the copied string. 
 * It returns the length of @p src, regardless of the 
 * number of characters copied.
 *
 * If @p size is 0, @p dest is not modified, 
 * and the function simply returns the length of @p src.
 *
 * @param dest The destination buffer where @p src will be copied.
 * @param src The source string to copy from.
 * @param size The size of the destination buffer, 
 * including space for the null-terminator.
 *
 * @return The length of @p src (aka size - 1), 
 * indicating the total length of the string that would have been 
 * created if there were enough space in 
 * @p dest. If @p dest or @p src are `NULL`the function 
 * returns `-1` as error indicator.
 *
 * Example:
 * 
 * `char buffer[10];`
 * `size_t result = ft_strlcpy(buffer, "Hello, world!", sizeof(buffer))`
 * 
 *  -> buffer contains "Hello, wo" with null-termination 
 * 
 * -> result is the length of "Hello, world!", which is 13
 */
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
/**
 * @brief Calculates the length of the string @p str 
 * (excluding the null-terminator).
 *
 * @param str The input string whose length is to be calculated.
 * @return The number of characters in @p str, 
 * not including the null-terminator.
 *
 * Example:
 * 
 * `int len = ft_strlen("Hello, world!");` -> len is 13
 */
int					ft_strlen(const char *str);
/**
 * @brief Applies the function @p f to each character of the string @p s, 
 * passing its index as the first argument and the character itself
 *  as the second. A new string is created using malloc(3) to collect 
 * the results from the successive applications of f. The resulting string is
 * dynamically allocated and should be freed by the caller.
 *
 * @param s The input string on which to apply the function @p f.
 * @param f A function that takes an index and a character, 
 * returning a modified character.
 * @return A new string with each character modified by the function @p f, 
 * or NULL if allocation fails or str is equal to `NULL`
 * 
 * @note The returned string should be freed using `free()` 
 * to avoid memory leaks.
 *
 * Example:
 * 
 * `char *result = ft_strmapi("hello", to_uppercase);` 
 * -> result is "HELLO"
 * 
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief Compares up to @p n characters of two strings @p s1 and @p s2.
 *
 * This function compares the strings @p s1 and @p s2 up to @p n characters 
 * or until a difference is found. It returns an integer less than, 
 * equal to, or greater than zero if @p s1 is found, respectively, 
 * to be less than, to match, or to be greater than @p s2.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * @return An integer representing the difference between 
 * the first differing characters:
 * 
 * - 0 if the first @p n characters of both strings are identical.
 * or if one or both of the strings are equal to `NULL`
 * 
 * - A positive or negative value depending on the lexicographical 
 * difference of the differing characters.
 * 
 * @note It is not visible if the strings are equal or one / both
 * of the strings are equal to `NULL`
 * 
 *
 * Example:
 * 
 * `ft_strncmp("hello", "hello", 5);` -> Returns 0
 * 
 * `ft_strncmp("hello", "world", 5);` -> Returns a negative value
 * 
 * `ft_strncmp("apple", "app", 5);` -> Returns a positive value
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief Searches for the first occurrence of the substring 
 * @p little in the string @p big, but only within the first @p n characters.
 *
 * This function locates the first occurrence of the null-terminated string 
 * @p little in the string @p big, searching only up to the first 
 * @p n characters. The function returns a pointer to the beginning 
 * of the located substring, or `NULL` if the substring is not found.
 *
 * @param big The main string to search within.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search within @p big.
 * @return A pointer to the beginning of the substring if found 
 * within the first @p n characters of @p big. 
 * `NULL` if the substring is not found or if either 
 * @p big or @p little is NULL.
 *
 *
 * Example:
 * 
 * `ft_strnstr("Hello World", "World", 11);`
 * -> Returns pointer to "World" in "Hello World"
 * 
 * `ft_strnstr("Hello", "World", 5);`
 * -> Returns NULL as "World" is not found
 * 
 */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
/**
 * @brief Locates the last occurrence of character @p c in the string @p s.
 *
 * This function searches for the last occurrence of the character @p c 
 * in the null-terminated string @p s. If found, it returns a pointer to 
 * the position of @p c in the string; otherwise, it returns `NULL`.
 *
 * @param s The null-terminated string to search within.
 * @param c The character to locate.
 * @return A pointer to the last occurrence of @p c in @p s, 
 * or NULL if @p c is not found or if @p s is NULL. Returns `NULL` the 
 * string @p s is equal to `NULL`
 *
 * @note This function returns a pointer to the terminating 
 * null character if @p c is '\0'.
 *
 * Example:
 * ```c
 * ft_strrchr("Hello World", 'o'); // Returns pointer to the 'o' in "World"
 * ft_strrchr("Hello", 'z');       // Returns NULL as 'z' is not found
 * ```
 */
char				*ft_strrchr(const char *s, int c);
/**
 * @brief Trims the characters in the `set` from 
 * the beginning and end of the string `s1`.
 *
 * The function removes any characters from `set` that appear at the 
 * start or end of `s1`, returning a new string with only the middle 
 * portion of `s1` that is free from these characters.
 * 
 * @param s1 The original string to be trimmed.
 * @param set A set of characters to trim from the beginning and end of `s1`.
 * @return A newly allocated trimmed string, or NULL if either 
 * allocation fails or one of the input parameters is equal to `NULL`
 * @note The returned string should be freed by the caller using `free()` 
 * to avoid memory leaks.
 *
 * Example:
 * 
 * `char *result = ft_strtrim("  -hello-  ", " -");` -> returns "hello"
 */
char				*ft_strtrim(char const *s1, char const *set);
/**
 * Extracts a substring from the given string `s`, starting at 
 * index `start` and of length `len`.
 * 
 * @param s The original string from which to extract the substring.
 * @param start The starting index within `s` from which 
 * to begin the substring.
 * @param len The maximum length of the substring to extract.
 * @return A newly allocated string containing the extracted substring, 
 * or NULL either if allocation fails or if @p s is equal to `NULL`
 * 
 * @note Ensure to free the returned string using `free()` 
 * to avoid memory leaks.
 * 
 * Example:
 * 
 * `char *result = ft_substr("hello", 1, 3);` -> returns "ell"
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * Converts an uppercase letter to its lowercase equivalent.
 * If the character is not an uppercase letter, 
 * it returns the character unchanged.
 * 
 * @param c The character to convert to lowercase.
 * @return The lowercase equivalent of `c` if it's an uppercase letter, 
 * otherwise the original character.
 * 
 * Example:
 * 
 * `int result = ft_tolower('A');` -> result = 'a'
 */
int					ft_tolower(int c);
/**
 * Converts a lowercase letter to its uppercase equivalent.
 * If the character is not a lowercase letter, 
 * it returns the character unchanged.
 * 
 * @param c The character to convert to uppercase.
 * @return The uppercase equivalent of `c` if it's a lowercase letter, 
 * otherwise the original character.
 * 
 * Example:
 * 
 * `int result = ft_toupper('a');` -> result = 'A'
 */
int					ft_toupper(int c);

#endif
