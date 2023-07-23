#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/** path - function to find a command in the PATH */

int main(void)
{
	char *path;
	char *total, *cmd;
	struct stat buf;

	path = getenv("PATH");
	total = strdup(path);

	while (total)
	{
		cmd = strtok(total, ":");
		if (stat(cmd, &buf) == 0)
		{
			char *command = strdup(cmd);
			printf("command found %s\ ", command);
			free(cmd);
			free(path);
			free(total);

			return 0;
		}
		total = strtok(NULL, ":");
	}

	free(path);
	free(total);
	return 0;
}

