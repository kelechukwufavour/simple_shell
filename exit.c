#include "shell.h"
/**/

void shell_exit(char **line, char **argv, char *run)
{
	int check = 0;
	int a = 0;
	(void)argv;

	if (line[1] == NULL)
	{
		free(run);
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
			free(run);
			free(line);
			exit(2);
		}
	}

	free(run);
	free(line);
	exit(check);
}

