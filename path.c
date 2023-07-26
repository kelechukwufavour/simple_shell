#include "shell.h"
#define SIZE 100

int find_file_in_path(const char *filename)
{
	char *total;
	struct stat st;
	char fullPath[SIZE];
	char *totalPath = getenv("PATH");
	size_t len;

	total = strtok(totalPath, ":");

	do {
		my_strcpy(fullPath, total);
		my_strcat(fullPath, "/");
		my_strcat(fullPath, filename);
		len = my_strlen(fullPath);

		if (stat(fullPath, &st) == 0)
		{
			write(1, " ", 1);
			write(1, fullPath, len);
			write(1, " found\n", 7);
			return (0);
		}
	} while ((total = strtok(NULL, ":")));

	write(1, " ", 1);
	write(1, fullPath, len);
	write(1, " Not found\n", 11);

	return (0);
}

