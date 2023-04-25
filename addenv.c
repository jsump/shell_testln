#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the address of env, third parameter of mian function
 * Return: 0
 */
extern char **environ;

int main(void)
{
	char **env = environ;

	printf("Address of env: %p\n", (void *)&env);
	printf("Address of environ: %p\n", (void *)&environ);

	return 0;
}
