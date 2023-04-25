#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *dir;
	struct node *next;
} node_t;

node_t *build_path_list()
{
	node_t *head = NULL;
	char *path = getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "Error: PATH environment variable not found\n");
		return NULL;
	}
	char *path_copy = strdup(path);
	if (!path_copy)
	{
		perror("Error: Failed to allocate memory");
		return NULL;
	}
	char *dir = strtok(path_copy, ":");
	while (dir)
	{
		node_t *node = malloc(sizeof(node_t));
		if (!node)
		{
			perror("Error: Failed to allocate memory");
			return NULL;
		}
		node->dir = strdup(dir);
		node->next = head;
		head = node;
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return head;
}
int main(void)
{
	node_t *head = build_path_list();
	if (!head)
	{
		fprintf(stderr, "Error: Failed to build path list\n");
		return EXIT_FAILURE;
	}
	node_t *node = head;
	while (node)
	{
		printf("%s\n", node->dir);
		node = node->next;
	}
	return EXIT_SUCCESS;
}
