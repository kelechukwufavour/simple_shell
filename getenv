#include "shell.h"
#include <stdlib.h>

/**
* getenv - retrieves the value of an environment variable
* @name: var
* Return: variable name (var)
*/
char *getenv(const char *name)
{
list_t *node = info->env;
char *a;
size_t length;

while (node)
{
a = starts_with(node->str, name);
if (a && *a)
{
/* Calculate the length of the string */
length = 0;
while (a[length] != '\0')
{
length++;
}

/* Allocate memory for the new string */
char *var = malloc((length + 1) * sizeof(char));

if (var == NULL)
{
return (NULL); /* Memory allocation failed */
}

/* Copy the string to the newly allocated memory */
for (size_t i = 0; i <= length; i++)
{
var[i] = a[i];
}

free(a);
return (var);
}
node = node->next;
}

return (NULL);
}
