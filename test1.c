#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *cmd = NULL;
	char *cmd_cpy = NULL;
	char *token = NULL;
	char *delim = " \n";
	size_t n = 0;
	int argc = 1; /* Initialize to 1 to count the first argument */
	int i = 0;
	char **argv = NULL;

	while (1)
	{
		printf("$ ");

		if (getline(&cmd, &n, stdin) == -1)
		{
			free(cmd);
			printf("\nExiting the shell...\n");
			exit(0);
		}

		cmd_cpy = strdup(cmd);

		token = strtok(cmd, delim);
		while (token)
		{
			token = strtok(NULL, delim);
			if (token)
				argc++;
		}

		printf("%d\n", argc);

		argv = malloc(sizeof(char *) * argc);

		token = strtok(cmd_cpy, delim);
		while (token)
		{
			argv[i] = strdup(token);
			/* Allocate memory for each argument and copy the token*/
			token = strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL;

		i = 0;
		while (argv[i])
		{
			printf("%s\n", argv[i]);
			free(argv[i]);
			/* Free allocated memory for each argument*/
			i++;
		}

		free(cmd);
		free(cmd_cpy);
		free(argv);
		/* Free the argv array*/

		argc = 1;
		/* Reset argc for the next iteration*/
	}

	return 0;
}

