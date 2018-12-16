// Program that demonstrates parent process waiting for child process to complete
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// Create processes in loop, wait for them to complete
	for (int i = 0; i < 10; i++)
	{
		pid_t child_pid = fork();

		if (!child_pid)
		{
			// We're executing child, wait for some random duration upto 10 seconds and exit
			srand(time(NULL));
			long random_sleep = rand() % 10;

			pid_t child_pid = getpid();
			printf("This is child with pid %ld, sleeping for %ld and exiting!\n", (long) child_pid, random_sleep);
			
			sleep(random_sleep);
			break;
		}
		else 
		{
			// We're executing parent, wait for child execution to complete and
			// print the appropriate message as per child termination code
			int child_status;
			child_pid = wait(&child_status);

			if (child_pid == -1) 
			{
				printf ("Error in wait!");
				exit(EXIT_FAILURE);
			}
			else
			{
				if (WIFEXITED(child_status))
				{
					printf ("Normal termination of child with PID %ld\n", (long) child_pid);
				}
				else if (WIFSIGNALED(child_status))
				{
					printf ("Signal termination of child with PID %ld with signal %d\n", 
							(long) child_pid, 
							WTERMSIG(child_status));
				}

			}
		}
	}

	exit(EXIT_SUCCESS);
}
