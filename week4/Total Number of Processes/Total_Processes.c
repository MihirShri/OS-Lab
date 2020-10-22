#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int c = 0;

	while(1)
	{
		int pid = fork();
		if (pid < 0)
		{
			printf("The total number of processes is %d\n", c+1);
			break;
		}
		if (pid == 0)
		{
			exit(0);
		}
		c++;
	}
	
	return 0;

}

