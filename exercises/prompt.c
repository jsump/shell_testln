#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prompt user for input and display it back
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (getline(&line, &len, stdin) == -1)
		{
			break;
		}
		printf("%s", line);
	}
	free(line);
	return (0);
}
