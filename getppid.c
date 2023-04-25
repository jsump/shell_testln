#include <stdio.h>
#include <unistd.h>
/**
 * get_ppid - get process ID of parent process
 * Return: ID of process parent
 */
ppid_t get_ppid(void)
{
	return (getppid());
}
