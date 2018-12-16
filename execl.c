// Program that demonstrates executing a binary by using execl system call
// We provide the path to binary, and arguments
// Currently this only works when executing from the same directory as execl and pid
// TODO: Update this when I know how to use pwd into code

#include <unistd.h>
#include <stdio.h>

int main() 
{
	printf("Executing pid binary from the same directory...\n");
	int ret = execl("./pid", "pid", NULL);
	if (ret == -1)
	{
		perror("execl failed");
	}

	return 0;
}
