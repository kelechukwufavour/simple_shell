#include "shell.h"

/**
 * my_strcat - strcat function to concatenate two strings
 * @dest: The destination string
 * @src: The source string
 * Return: The pointer to destination string
 */
char *my_strcat(char *dest, const char *src)
{
	/*Find the end of the destination string*/
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}
