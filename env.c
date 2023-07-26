#include "shell.h"

/*
 * print_environment - function to print the environment variables
 * @description:This function prints all the environment variables to the
 * standard output
 * @env: The environment array.
 * return: 0
 */

void print_environment(char **env)
{

	/* Iterate through each environment variable and print them*/
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, my_strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;

	}

}



