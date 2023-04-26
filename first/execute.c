#include "shell.h"
/**
 * execute_command - checks if command is present and exits the program
 * @command: command to be inputed by user
 */
void execute_command(char *command)
{
	pid_t pid;
	int status_of_process;
	char *args[2];
	char *path;
	char *createtoken;

	args[0] = command;
	args[1] = NULL;
	path = getenv("PATH");
	createtoken = strtok(path, ":");

	while (createtoken != NULL)
	{
		char whole_path[1024];

		sprintf(whole_path, "%s/%s", createtoken, command);
		status_of_process = execve(whole_path, args, NULL);
		if (status_of_process >= 0)
			break;
		createtoken = strtok(NULL, ":");
	}
	if (command[0] == '/')
		status_of_process = execve(command, args, NULL);
	if (status_of_process < 0)
		printf("Error: Command not found: %s\n", command);
	pid = fork();
	if (strcmp(command, "exit\n") == 0)
		exit(0);
	else if (strcmp(command, "env\n") == 0)
	{
		char **env = __environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		return;
	}
	if (pid < 0)
	{
		printf("Error: Could not be forked\n");
		return;
	}
	if (pid == 0)
	{
		if (status_of_process < 0)
		{
			printf("Error: %s\n", strerror(errno));
			exit(1);
		}
		else
			waitpid(pid, NULL, 0);
	}
}
