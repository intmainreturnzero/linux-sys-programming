// Code snippet that calls fork and execs the pid binary.
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <inttypes.h>
// Including to use exit()
#include <stdlib.h>

int main() 
{
	// Print the pid of this process first
	printf("pid of this (parent) process is %jd\n", (intmax_t) getpid());

	// Now fork the process
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error in fork!");
	}

	// Only execute the below code in child process
	if (!child_pid)
	{
		int ret = execl("./pid", "pid", NULL);

		if (ret == -1)
		{
			perror("Error in execl!");
			exit(EXIT_FAILURE);
		}
	}

	// End parent and child process with 0
	exit(EXIT_SUCCESS);
}
