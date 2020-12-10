#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *runner(void *param);

int prime(int n)
{
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
			c++;
	}

	if(c==2)
		return 1;

	else
		return 0;
}

int main(int argc, char const *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: ./a.out <n>\n");
		return -1;
	}

	int n = atoi(argv[1]);

	printf("Prime numbers upto %d are:\n", n);

	for (int i = 2; i <= n; i++)
	{
		int *nums = (int*)malloc(sizeof(int));
		nums[0] = i;
		pthread_attr_init(&attr);
		pthread_create(&tid, &attr, runner, nums);
		pthread_join(tid, NULL);
	}

	printf("\n");

	return 0;
}

void *runner(void *param)
{
	int *nums = (int *)param;
	int num = nums[0];

	if (prime(num))
		printf("%d ", num);

	pthread_exit(0);
}