#include "shell.h"

/**
 * shell_exit - closes the shell.
 * @line: to be freed.
 * @st: to be freed.
*/

void shell_exit(char **line, char *st)
{
	int check = 0;
	int a = 0;

	if (line[1] == NULL)
	{
		free(st);
		free(line);
		exit(0);
	}

	/* custom function to check if the argument is a valid number */
	while (line[1][a])
	{
		if (line[1][a] >= '0' && line[1][a] <= '9')
		{
			check = check * 10 + (line[1][a] - '0');
			a++;
		}
		else
		{
			write(STDERR_FILENO, "not found\n", 10);
			free(st);
			free(line);
			exit(2);
		}
	}

	free(st);
	free(line);
	exit(check);
}

