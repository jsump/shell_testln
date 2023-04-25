#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_path_directories(void)
{
	char *path_env = getenv("PATH");
	if (path_env == NULL)
	{
		printf("PATH environment variable not set\n");
		return;
	}
	char *path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("strdup");
		return;
	}
	char *dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
}

int main(void)
{
	print_path_directories();
	return 0;
}
