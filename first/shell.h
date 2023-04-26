#ifndef shell_h
#define shell_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
extern char **environ;

void display_prompt(void);
void execute_command(char *command);
void print_environment(void);

#endif

