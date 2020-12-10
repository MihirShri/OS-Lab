#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	int pipefds1[2], pipefds2[2];
	int returnstatus1, returnstatus2;
	int pid;
	char pipe1writemessage[20] = "Hi";
	char pipe2writemessage[20] = "Hello";
	char readmessage[20];

	returnstatus1 = pipe(pipefds1);

	if (returnstatus1 == -1)
	{
		printf("Unable to create Pipe 1\n");
		return 1;
	}

	returnstatus2 = pipe(pipefds2);

	if (returnstatus2 == -1)
	{
		printf("Unable to create Pipe 2\n");
		return 1;
	}

	pid = fork();

	if (pid > 0)
	{
		close(pipefds1[0]);
		close(pipefds2[1]);

		printf("Parent writing to pipe 1. Message sent to child is - %s\n", pipe1writemessage);

		write(pipefds1[1], pipe1writemessage, sizeof(pipe1writemessage)+1);

		read(pipefds2[0], readmessage, sizeof(readmessage));

		printf("Parent read from pipe 2. Message read from child is - %s\n", readmessage);
	}

	else
	{
		close(pipefds1[1]);
		close(pipefds2[0]);

		read(pipefds1[0], readmessage, sizeof(readmessage));

		printf("Child read from pipe 2. Message read from parent is - %s\n", readmessage);

		printf("Child writing to pipe 1. Message sent to parent is - %s\n", pipe2writemessage);

		write(pipefds2[1], pipe2writemessage, sizeof(pipe2writemessage)+1);

	}

	return 0;
}
