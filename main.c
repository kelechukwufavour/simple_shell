#include "shell.h"


int main (int argc, char* av[], char **env)
{
	pid_t pid;
	int status, count = 0;
	pid_t ppid = getpid();
	size_t n = 0;
	struct stat *st = malloc(sizeof(struct stat));
	char *line, *tok;
	char *argv[100] = {"", "-l", NULL,"/tmp", NULL};
	char *buf = "DMD&FAVOUR'S SHELL";

	/** Handle Arguments**/
	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, buf, 20);

		if (getline(&line, &n, stdin) == -1)
		{
			exit(0);
		}

		tok = strtok(line, "  \n\r\v\b\f\t ");
		argv[0] = tok;
		while (argv[count] != NULL)
		{
			count = count+1;
			argv[count] = strtok(NULL, " ");
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
						exit(EXIT_FAILURE);						}
				else
				{
					wait(&status);
					if (status != 0)
						exit (2); 
				}
			}
			else
			{
				perror(av[0]);
			}
		}
	}
	exit(EXIT_SUCCESS);
}
