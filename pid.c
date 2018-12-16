// For getpid function
#include <unistd.h>
// For printf
#include <stdio.h>
// For intmax_t
#include <inttypes.h>

int main()
{
	printf ("My (getpid's) pid=%jd\n", (intmax_t) getpid());
	return 0;
}
