#include "shell.h"

/**
 * my_strlen - A function to return the length of a string
 * @str: the string length to check
 *
 * Return: integer length of string
 */
int my_strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);

}
/**
 * my_strcmp - A function to compare two null terminated strings
 * @str1: first string
 * @str2: second string
 * Return: Zero if str1 == str2, positive if str1 > str2,
 * Negative if str1 < str2
 */
int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);

		str1++;
		str2++;
	}

	return (*str1 - *str2);
}
