// Program that demonstrates executing a binary by using execl system call
// We provide the path to binary, and arguments
// Currently this only works when executing from the same directory as execl and pid
// TODO: Update this when I know how to use pwd into code

#include <unistd.h>
#include <stdio.h>
#include <inttypes.h>

int main() 
{
	printf("My pid is %jd\n", (intmax_t) getpid());
	printf("Executing pid binary from the same directory...\n");

	// The following call will start executing the pid binary.
	// This will have the same PID as process executing this binary. This can be seen from output.
	// Anything after execl call won't be executed unless execl fails.
	int ret = execl("./pid", "pid", NULL);

	if (ret == -1)
	{
		perror("execl failed");
	}
	
	printf("This won't be printed since the address space is overwritten");
	
	return 0;
}
