#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#define totchars 128
#define MAX 9

int freq[totchars] = {0};
char text[2000];
void *runner(void *param);

int main()
{
	printf("------------------Parallel Execution------------------\n");
	clock_t t; 
    
    printf("Some random string generated...\n\n");

    //Data for generating random string
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i'}; 
  
  	//generating random string
    for (int i = 0; i < 2000; i++)  
        text[i] = alphabet[rand() % MAX];

    //clock started
    t = clock(); 

	pthread_t tid[2000];

	int j = 0;

	//looping through the entire string and creating a thread only if a character is not visited i.e. unique
	for (int i = 0; i < strlen(text); i++)
	{
		if (freq[(int)text[i]] == 0)
		{
			freq[(int)text[i]] = 1;
			pthread_create(&tid[j++], NULL, runner, (void*)i);	
		}
	}

	int num = j;
	j = 0;

	//Joining the threads
	while (j < num)
	{
		pthread_join(tid[j++], NULL);
	}
 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("Threaded program took %f seconds to execute \n\n", time_taken);
    printf("Total number of threads created = %d\n", num);

	return 0;
}

void *runner(void *param)
{
	int *n = (int *)param;
	int i = n;
	int j;

	//The runner function loops through the entire string and counts the occurance of the character which is sent by the main function
	for (j = 0; j < strlen(text); j++)
	{
		if (text[j] == text[i])
		{
			freq[(int)text[i]]++;
		}
	}

	printf("%c (%d) ", text[i], freq[(int)text[i]]-1);
	for(j=0; j < freq[(int)text[i]]-1; j++) 
		printf("*");

	printf("\n");


	pthread_exit(0);
}