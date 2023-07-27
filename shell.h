#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

/***************************USER DEFINED FUNCTIONS**********************/
int my_strlen(const char *str);
void print_environment(char **env);
int my_strcmp(const char *str1, const char *str2);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);
void print_er127(char *argv0, struct stat *st,  char *line);
void exec(char **argv, struct stat *st, char **env, char *line);
void parsenexec(char **argv, struct stat *st, char *line, char **env);
void freeinits(char *line, struct stat *st);
char *getenv(const char *name);
int setenv_builtin(char **args);
int unsetenv_builtin(char **args);


/* ************************* Function prototypes***************************/

#define SIZE 100
#endif /* SHELL_H*/
