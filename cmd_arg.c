#include "shell.h"

/**
 * print_er127 - prints error 127
 * @argv0: argument for printing.
 * @st: verifier
 * @line: line from user.
 */
void print_er127(char *argv0, struct stat *st, char *line)
{
	int len;

	len = my_strlen(argv0);
	/**perror(av[0]);*/
	write(STDERR_FILENO, "./hsh: 1: ", 10);
	write(STDERR_FILENO, argv0, len);
	write(STDERR_FILENO, ": not found\n", 12);
	if (!isatty(STDIN_FILENO))
	{
		free(line);
		free(st);
		exit(127);
	}
	/*[./hsh: 1: ls: not found*/
}

/**
 * exec - executes commnd
 * @argv: argument for command.
 * @st: program verifier.
 * @env: environment variable.
 * @line: line from user.
 */

void exec(char **argv, struct stat *st, char **env, char *line)
{
	int status;
	pid_t pid;

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
		print_er127(argv[0], st, line);
	}
}

/**
 * parsenexec - parses line from user and call exec.
 * @argv: argument for command.
 * @st: program verifier.
 * @line: lne of text to be parsed
 * @env: environment variable.
 */

void parsenexec(char **argv, struct stat *st, char *line, char **env)
{
	char *tok;
	int ar;

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
		exec(argv, st, env, line);
	}
}

/**
 * freeinits - frees line and st.
 * @st: program verifier.
 * @line: lne of text to be parsed
 */

void freeinits(char *line, struct stat *st)
{
	free(line);
	free(st);
}

/**
 * main - program entry point.
 * @argc: number of arguments.
 * @av: array of arguments.
 * @env: environment variable.
 *
 * Return: status
 */

int main(int argc, char *av[], char **env)
{
	size_t n;
	struct stat *st = malloc(sizeof(struct stat));
	char *line, *buf = "$ ";
	char *argv[50];
	(void)av;
	(void)argc;

	while (1) /** Handle Arguments**/
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, buf, 2);
		if (getline(&line, &n, stdin) == -1)
		{
			freeinits(line, st);
			exit(0);
		}
		if (my_strcmp(line, "env\n") == 0)
		{
			print_environment(env);
		}
		else if (my_strcmp(line, "exit\n") == 0)
		{
			freeinits(line, st);
			exit(0);
		}
		else
		{
			parsenexec(argv, st, line, env);
		}
	}
	freeinits(line, st);
	exit(EXIT_SUCCESS);
}
