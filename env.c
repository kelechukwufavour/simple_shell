#include "shell.h"

/**
 * print_environment - function to print the environment variables.
 * @env: The environment array.
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



