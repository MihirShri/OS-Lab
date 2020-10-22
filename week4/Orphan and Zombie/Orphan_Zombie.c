#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int pid = fork();

	if(pid == 0)
	{	
		int pido = fork();
		
		if(pido > 0)	// Parent
		{
			printf("(Orphan)Parent executed..\n");
			return 0;
		}
		
		else if(pido == 0)	// Child
		{
			sleep(2.5);	// Wait 2.5

			printf("(Orphan)Child executed -- Orphan as no parent....\n");
			return 0;
		}

		printf("\n");
	}
	
	else if(pid > 0)
	{
		wait(NULL);
		
		int pidz = fork();
		
		if(pidz == 0)	// Child
		{
			printf("(Zombie)Child executed..\n");
			exit(0);
			return 0;
		}
		
		else if(pidz > 0)	// Parent
		{
			sleep(2.5);	// Wait 2.5    // Now this parent is executed but all of its children have executed already and exited

			printf("(Zombie)Parent executed -- Zombies child has already exited....\n");
			return 0;
		}

		printf("\n");
		return 0;
	}
	
}
