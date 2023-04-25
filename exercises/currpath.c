#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PATH_MAX_LENGTH 4096

/**
* Find the file with the given name in the current PATH.
*
* @param filename The name of the file to look for.
* @param path The current PATH.
* @return The full path to the file, or NULL if not found.
*/
char *find_file(const char *filename, const char *path)
{
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char full_path[PATH_MAX_LENGTH];
		snprintf(full_path, PATH_MAX_LENGTH, "%s/%s", dir, filename);

		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return strdup(full_path);
		}

		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return NULL;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return 1;
	}

	char *path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set.\n");
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		char *full_path = find_file(argv[i], path);

		if (full_path != NULL)
		{
			printf("%s\n", full_path);
			free(full_path);
		}
		else
		{
			fprintf(stderr, "%s: command not found\n", argv[i]);
		}
	}

	return 0;
}
