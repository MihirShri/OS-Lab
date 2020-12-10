#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

void *runner1(void *param);
void *runner2(void *param);
void *runner3(void *param);

int main(int argc, char const *argv[])
{
	pthread_t tid1, tid2, tid3;
	pthread_attr_t attr1, attr2, attr3;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: ./a.out <element 1> <element 2> <element 3> ...\n");
		return -1;
	}

	int n = argc;
	int *nums = (int *)malloc(n * sizeof(int *));
	nums[0] = n;

	for (int i = 1; i < argc; i++)
	{
		nums[i] = atoi(argv[i]);
	}

	pthread_attr_init(&attr1);
	pthread_create(&tid1, &attr1, runner1, nums);

	pthread_attr_init(&attr2);
	pthread_create(&tid2, &attr2, runner2, nums);

	pthread_attr_init(&attr3);
	pthread_create(&tid3, &attr3, runner3, nums);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	return 0;
}

void *runner1(void *param)
{
	int *nums = (int *)param;
	float n = nums[0];
	float sum = 0, mean;

	for (int i = 1; i < n; i++)
	{
		sum += nums[i];
	}

	mean = sum / (n-1);
	printf("The Mean is : %f\n", mean);

	pthread_exit(0);
}

void *runner2(void *param)
{
	int *nums = (int *)param;
	int n = nums[0];
	int *new_nums = (int *)malloc(n * sizeof(int *));
	float median;

	for (int i = 0; i < n-1; i++)
		new_nums[i] = nums[i+1];

	sort(new_nums, new_nums+n-1);

	if ((n-1) % 2 != 0)
		median = new_nums[(n-1)/2];

	else
		median = (new_nums[((n-1)/2) - 1] + new_nums[((n-1)/2)]) / 2.0;

	printf("The Median is: %f\n", median);

	pthread_exit(0);
}

void *runner3(void *param)
{
	int *a = (int *)param;
	int n = a[0];
	int *b = (int *)malloc(n * sizeof(int *));
	int mode, k = 0, c = 1, max = 0;

	for (int i = 0; i < n-1; i++)
		a[i] = a[i+1];

	n--;
	sort(a, a+n);

	for(int i = 0; i < n-1; i++)
  	{
  		mode = 0;

  		for(int j = i+1; j < n; j++)
   		{
   			if(a[i]==a[j])
    		{
    			mode++;
    		}
   		}

  		if((mode > max) && (mode != 0))
   		{
   			k = 0;
   			max = mode;
   			b[k] = a[i];
   			k++;
   		}

  		else if(mode == max)
   		{
   			b[k] = a[i];
   			k++;
   		}
  	}

 	for(int i = 0; i < n; i++)
  	{
  		if(a[i] == b[i])
  			c++;
  	}

 	if(c == n+1)
 		printf("There is no mode\n");

 	else
  	{
  		printf("The Mode is: ");

  		for(int i = 0; i < k; i++)
  			printf("%d ",b[i]);
  	}

  	printf("\n");

  	pthread_exit(0);
}
