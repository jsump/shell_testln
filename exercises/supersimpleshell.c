#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10
/** main - simple super shell
 * Return: 0
 */
int main(void)
{
	char input[100]; // buffer to hold user input
	char *args[MAX_ARGS + 1]; // array to hold arguments
	pid_t pid; // process id of child process
	int status; // status of child process

	while (1)
	{
		printf("$ ");
		fflush(stdout); // flush output to ensure prompt is displayed

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		char *arg = strtok(input, " ");
		int i = 0;
		while (arg != NULL && i < MAX_ARGS)
		{
			args[i++] = arg;
			arg = strtok(NULL, " ");
		}
		args[i] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
	return 0;
}
