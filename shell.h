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

/************************** Function prototypes***************************/
void shell_init(void);
char *read_input(void);
void handle_arguments(char *line, char **env);
void execute_command(char **argv, char **env);

#define SIZE 100
#endif /* SHELL_H*/
