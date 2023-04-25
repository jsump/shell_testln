#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || *name == '\0')
	{
		return -1;
	}

	char *var = malloc(strlen(name) + strlen(value) + 2);
	if (var == NULL)
	{
		return -1;
	}

	strcpy(var, name);
	strcat(var, "=");
	strcat(var, value);

	int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			if (overwrite)
			{
				environ[i] = var;
			}
			else
			{
				free(var);
				return 0;
			}
		}
	}

	char **new_environ = realloc(environ, (i + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		free(var);
		return -1;
	}

	environ = new_environ;
	environ[i] = var;
	environ[i + 1] = NULL;

	return 0;
}
int main(void)
{
	printf("Before _setenv:\n");
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
	_setenv("MY_VAR", "new_value", 1);
	printf("\nAfter _setenv:\n");
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
	return 0;
}
