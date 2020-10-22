#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

#define totchars 128

int main()
{
	char text[500];

	while(1)
	{
		printf("Enter the text: ");
		gets(text);

		int freq[totchars] = {0};
		
		int pid = vfork();

		if(pid == 0)
		{
			for(int i=0;i<strlen(text);i++)
			{
				freq[(int)text[i]]++;
			}
			
			exit(0);
		}
		
		else if (pid > 0)
		{
			wait(NULL);

			for(int i=32;i<totchars-1;i++)
			{
				printf("%c (%d) ", (char)i, freq[i]);
				for(int j=0;j<freq[i];j++) printf("*");
				printf("\n");
			}

			printf("\n\n");

			int exit = 0;
			printf("Do you want to exit: ");
			scanf("%d", &exit);
			
			if(exit == 1)
			{
				return 0;
			}
		}
	}
}
