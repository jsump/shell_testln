#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - exec+fork+wait
 * Return: 0
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t pid;
	int status;

	for (int i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return 1;
		}
		else if (pid == 0)
		{
			printf("Child %d executing...\n", i+1);
			execve(argv[0], argv, NULL);
			perror("execve");
			return 1;
		}
		else
		{
			printf("Parent waiting for child %d...\n", i+1);
			wait(&status);
			printf("Child %d exited with status %d.\n", i+1, WEXITSTATUS(status));
		}
	}
	return 0;
}
