#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - prin the environment using global var environ
 * Return: 0
 */
extern char **environ;

int main(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
