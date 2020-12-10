#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#define totchars 128
#define MAX 26
int freq1[totchars] = {0};
char text1[2000];
void process(int i, char text1[]);

int main()
{
    clock_t t;
    printf("------------------Serial Execution------------------\n");

    //Data for generating random string
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z' }; 
  
    //generating random string
    for (int i = 0; i < 2000; i++)  
        text1[i] = alphabet[rand() % MAX];

    //clock started
    t = clock();

    //looping through the entire string and calling the process function only if a character is not visited i.e. unique
    for(int i = 0; i < strlen(text1); i++)
    {
        if (freq1[(int)text1[i]] == 0)
        {
            freq1[(int)text1[i]] = 1;
            process(i, text1);
        }
    }


    t = clock() - t;
    double time_taken1 = ((double)t)/CLOCKS_PER_SEC;

    printf("Serial execution took %f seconds to execute\n", time_taken1);

    return 0;
}

void process(int i, char text1[])
{
    //The process function loops through the entire string and counts the occurance of the character which is sent by the main function
    for (int j = 0; j < strlen(text1); j++)
    {
        if (text1[j] == text1[i])
        {
            freq1[(int)text1[i]]++;
        }
    }

    printf("%c (%d) ", text1[i], freq1[(int)text1[i]]);
    for(int j = 0; j < freq1[(int)text1[i]]; j++) 
        printf("*");


    printf("\n");
}
