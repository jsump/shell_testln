#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
extern char **environ;
int _unsetenv(const char *name)
{
	if (name == NULL || *name == '\0' || strchr(name, '=') != NULL)
	{
		return -1;
	}

	size_t name_len = strlen(name);
	char **p = environ;
	while (*p != NULL)
	{
		if (strncmp(*p, name, name_len) == 0 && (*p)[name_len] == '=')
		{
			for (char **q = p; *q != NULL; q++)
			{
				*q = *(q + 1);
			}
			return 0;
		}
		p++;
	}

	return 0;
}
extern char **environ;

int main(void)
{
	printf("Before _unsetenv:\n");
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}

	_unsetenv("MY_VAR");

	printf("\nAfter _unsetenv:\n");
	for (char **env = environ; *env != NULL; env++)
	{
	printf("%s\n", *env);
	}

	return 0;
}
