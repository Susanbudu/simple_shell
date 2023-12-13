#include "shell.h"

/**
 * custom_string_length - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t custom_string_length(const char *str)
{
    size_t length = 0;

    while (*str != '\0')
    {
        length++;
        str++;
    }

    return length;
}

/**
 * custom_substring - Find the first occurrence of a substring in a string.
 * @main_string: The string to search in.
 * @substring: The substring to search for.
 *
 * Return: A pointer to the first occurrence
 * of the substring, or NULL if not found.
 */
char *custom_substring(const char *main_string, const char *substring)
{
    const char *main_ptr = main_string;
    const char *sub_ptr = substring;

    if (custom_string_length(substring) == 0)
    {
        return (char *)main_string;
    }

    while (*main_string)
    {
        while (*sub_ptr && (*main_ptr == *sub_ptr))
        {
            main_ptr++;
            sub_ptr++;
        }
        if (!*sub_ptr)
        {
            return (char *)main_string;
        }
        main_string++;
    }

    return NULL;
}

/**
 * custom_string_compare - Compare two strings up to a specified number of characters.
 * @str1: The first string.
 * @str2: The second string.
 * @limit: The maximum number of characters to compare.
 *
 * Return: The difference between the first differing characters or 0 if equal.
 */
int custom_string_compare(const char *str1, const char *str2, size_t limit)
{
    size_t length1 = custom_string_length(str1);
    size_t length2 = custom_string_length(str2);
    size_t iterator = 0, min_length;
    unsigned char char1, char2;

    char1 = (unsigned char)*(str1 + iterator);
    char2 = (unsigned char)*(str2 + iterator);
    min_length = (length1 < length2) ? length1 : length2;

    if (limit > min_length)
    {
        limit = min_length;
    }

    iterator = 0;
    while (iterator < limit)
    {
        if (char1 != char2)
        {
            return char1 - char2;
        }
        iterator++;
    }
    return 0;
}

/**
 * custom_string_concatenate - Concatenate a source string to the end of a destination string.
 * @destination: The destination string.
 * @source: The source string to concatenate.
 *
 * Return: A pointer to the concatenated string.
 */
char *custom_string_concatenate(char *destination, const char *source)
{
    char *dest_ptr = destination;

    while (*dest_ptr != '\0')
    {
        dest_ptr++;
    }

    while (*source != '\0')
    {
        *dest_ptr = *source;
        dest_ptr++;
        source++;
    }

    *dest_ptr = '\0';
    return destination;
}

/**
 * custom_string_duplicate - Create a duplicate of a string.
 * @string: The input string to duplicate.
 *
 * Return: A pointer to the duplicated string,
 * or NULL if memory allocation fails.
 */
char *custom_string_duplicate(const char *string)
{
    size_t length = 0, index = 0;
    char *duplicate;

    if (!string)
    {
        return NULL;
    }

    while (string[length])
    {
        length++;
    }

    duplicate = (char *)malloc((length + 1) * sizeof(char));

    if (!duplicate)
    {
        return NULL;
    }

    while (string[index])
    {
        duplicate[index] = string[index];
        index++;
    }

    duplicate[index] = '\0';
    return duplicate;
}

