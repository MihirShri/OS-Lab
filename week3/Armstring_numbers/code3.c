#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main ()
{
	pid_t pid; // this is to use the pid data type – relevant headers above

	pid = fork();
	if (pid == 0)
		execl("/home/mihir/Desktop/OS/Lab/week3/processing", "./processing", NULL); // child image is now ./even

	else
	{
		wait (NULL); // parent waits for the child to complete execution.
		execl("/home/mihir/Desktop/OS/Lab/week3/check", "./check", NULL); // parent image is now ./odd
	}
	
	return 0;
}