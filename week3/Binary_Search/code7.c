#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main ()
{
	pid_t pid; // this is to use the pid data type – relevant headers above

	pid = fork();
	if (pid == 0)
	{
		execl("/home/mihir/Desktop/OS/Lab/week3/Q7/bin_first", "./bin_first", NULL); // parent image is now ./odd
	}

	else
	{
		wait (NULL);
		execl("/home/mihir/Desktop/OS/Lab/week3/Q7/bin_second", "./bin_second", NULL); // child image is now ./even
	}
	
	return 0;
}