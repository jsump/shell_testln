#include <stdio.h>
/**
 * main - prints arguments
 * @av: Null terminated array of strings
 * @ac: number of items in av
 * Return: 0
 */
int main(int ac, char **av)
{
	int k;

	for (k = 1; av[k] != NULL; k++)
	{
		printf("%s ", ac[k]);
	}
	printf("\n");
	return (0);
}
