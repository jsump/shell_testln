#include "shell.h"
#include <stdlib.h>
/**
 * print_environment - print current enrironment variables
 */
void print_environment(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
