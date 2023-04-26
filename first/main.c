#include "shell.h"
/**
 * main - entry or starting point
 * Return: 0
 */
int main(void)
{
	char buff[BUFFER_SIZE];

	while (1)
	{
		display_prompt();

		fgets(buff, BUFFER_SIZE, stdin);
		execute_command(buff);
	}
	return (0);
}
