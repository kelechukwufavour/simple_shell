#include "shell.h"


int main(int argc, char *av[], char **env)
{
	pid_t pid;
	int status = 0;
	size_t n;
	struct stat *st = malloc(sizeof(struct stat));
	char *line, *tok;
	char *argv[50];
	int ar, len;
	char *buf = "$ ";
	(void)av;
	(void)argc;

	/** Handle Arguments**/
	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, buf, 2);
		if (getline(&line, &n, stdin) == -1)
		{
			if (line)
				free(line);
			if (st)
				free(st);
			exit(0);
		}

		if (my_strcmp(line,  "env\n") == 0)
		{
			print_environment(env);
		}
		else if (my_strcmp(line, "exit\n") == 0)
		{
			exit(0);
		}
		else
		{
			tok = strtok(line, " \n\t\b\r\v");
			argv[0] = tok;
			ar = 0;
			while (argv[ar] != NULL)
			{
				ar++;
				argv[ar] = strtok(NULL, " \n\t\b\r\v");
			}

			if (argv[0] != NULL)
			{
				if (stat(argv[0], st) == 0)

				{
					pid = fork();
					if (pid == -1)
						exit(EXIT_FAILURE);
					if (pid == 0)
					{
						if (execve(argv[0], argv, env) == -1)
							exit(EXIT_FAILURE);
					}
					else
					{
						wait(&status);
						if (status != 0)
							exit(2);
					}
					/* free(st);*/
				}
				else
				{
					len = my_strlen(argv[0]);
					/**perror(av[0]);*/
					write(STDERR_FILENO, "./hsh: 1: ", 10);
					write(STDERR_FILENO, argv[0], len);
					write(STDERR_FILENO, ": not found\n", 12);
					exit(127);
					/*[./hsh: 1: ls: not found*/
				}
			}
		}

	}
	free(line);
	free(st);
	exit(EXIT_SUCCESS);
}
