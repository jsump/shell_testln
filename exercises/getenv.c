#include <stdio.h>
#include <string.h>

/**
 * _getenv - gets an env var without using getenv
 * @name: env name
 * Return: 0
 */
extern char **environ;

char *_getenv(const char *name)
{
	int i, len;
	char *value;
	len = strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			value = environ[i] + len + 1;
			return value;
		}
	}
	return NULL;
}
int main(void)
{
	char *path = _getenv("PATH");
	if (path == NULL)
	{
		printf("PATH environment variable not found\n");
	}
	else
	{
		printf("PATH = %s\n", path);
	}
	return (0);
}
