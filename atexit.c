// Code that demonstrates registration of functions to be invoked upon process termination
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void exit_handler_1()
{
	printf("Exit handler 1\n");
}

void exit_handler_2()
{
	printf("Exit handler 2\n");
}

void print_failure()
{
	printf("Error in registration of exit handler");
}

int main()
{	
	long atexit_max = sysconf(_SC_ATEXIT_MAX);
	printf("System supports max atexit stack size %ld\n", atexit_max);

	if (atexit_max > 2) {
		if (atexit(exit_handler_1))
		{
			print_failure();
		}
		if (atexit(exit_handler_2))
		{
			print_failure();
		}
	}
	

	printf("Exiting program from main...\n");

	exit(EXIT_SUCCESS);
}
