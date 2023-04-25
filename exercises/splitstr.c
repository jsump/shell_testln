#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * split_string - Splits a string into an array of words
 * @str: The string to split
 * @delim: The delimiter to use for splitting
 *
 * Return: A dynamically allocated array of strings, or NULL if an error occurs
 */
char **split_string(char *str, const char *delim)
{
	char **tokens = NULL;
	char *token = NULL;
	int count = 0;


	if (str == NULL || delim == NULL)
		return NULL;

	tokens = malloc(sizeof(char *));

	if (tokens == NULL)
		return NULL;


	token = strtok(str, delim);

	while (token != NULL)
	{
		tokens[count] = token;
		count++;
		
		tokens = realloc(tokens,(count + 1) * sizeof(char *));
		
		if (tokens == NULL)
			return NULL;

		token = strtok(NULL, delim);
	}

	tokens[count] = NULL;

	return tokens;
}

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char str[] = "This is a test string.";
	const char delim[] = " ";
	char **tokens;
	int i;

	tokens = split_string(str, delim);
	if (tokens == NULL)
	{
		printf("Error: could not split string\n");
		return 1;
	}

	for (i = 0; tokens[i] != NULL; i++)
	{
		printf("Token %d: %s\n", i, tokens[i]);
	}

	free(tokens);

	return 0;
}
