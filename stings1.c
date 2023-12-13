#include "shell.h"

/**
 * custom_copy_string - Copy a source string to a destination buffer.
 * @dest: The destination buffer.
 * @src: The source string.
 */
void custom_copy_string(char *dest, const char *src)
{
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

/**
 * custom_compare_strings - Compare two strings lexicographically.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: Negative if str1 is lexicographically less than str2,
 * positive if str1 is lexicographically greater than str2,
 * and 0 if both strings are equal.
 */
int custom_compare_strings(const char *str1, const char *str2)
{
    while (*str1 && *str2 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

/**
 * custom_atoi - Convert a string to an integer.
 * @str: The input string.
 *
 * Return: The integer value represented by the string.
 */
int custom_atoi(const char *str)
{
    int sign = 1, result = 0;

    while (*str == ' ')
    {
        str++;
    }

    if (*str == '-' || *str == '+')
    {
        sign = (*str++ == '-') ? -1 : 1;
    }

    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str++ - '0');
    }

    return sign * result;
}

/**
 * custom_strcspn - Calculate the length of the initial segment
 *                 of a string consisting of characters not in str2.
 * @str: The input string.
 * @str2: The characters to search for.
 *
 * Return: The length of the initial segment not containing characters in str2.
 */
size_t custom_strcspn(const char *str, const char *str2)
{
    size_t len = 0;

    while (*str && !strchr(str2, *str))
    {
        str++;
        len++;
    }

    return len;
}

