#include <stdio.h>
#include <unistd.h>
/**
 * get_pid - return the process ID of the current process
 * Return: ID of the current process
 */
pid_t get_pid(void)
{
	return (getpid());
}
