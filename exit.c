#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/** EXIT - Function to handle built-in "exit" command */

int main(void)
{
	char **line;
	char *run;
	char **argv;
	int arg;
	int a = 0;

	if (line[1] == NULL)
	{
		free(run);
		free(line);
		exit(0);
	}

	void handle_exit()
	{
		printf("Exiting DMD&FAVOUR'S SHELL.......%s\n");
		exit(0);
	}

	if (line[1] == NULL)
	{
		free(run);
		free(line);
		exit(0);
	}
	else
	{
		check = atoi(line[1]);
		/* Assuming check is an int variable to store the converted value of line[1] to integer.*/
		if (check >= 1)
		{
			perror("Error occurred:");
			free(run);
			free(line);
			exit(check);
		}
	}

	free(run);
	free(line);
	exit(0);
}

