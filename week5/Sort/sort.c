#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *runner(void *param);

int main(int argc, char const *argv[])
{
	int n;
	pthread_t tid;
	pthread_attr_t attr;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: ./a.out <element_1> <element_2> <element_3>...\n");
		return -1;
	}

	n = argc;
	int *result = (int *)malloc((n+1) * sizeof(int *));
	result[0] = n;

	for(int i = 1; i < argc; i++)
		result[i] = atoi(argv[i]);

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, (void *)result);
	pthread_join(tid, NULL);

	printf("Ascending Order: \n");

	for (int i = 1 ; i < n; i++)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if(result[j] < result[i])
			{
				int t = result[i];
				result[i] = result[j];
				result[j] = t;
			}
		}
	}

	for(int i=1;i<n;i++)
		printf("%d ", result[i]);

	printf("\n");

	free(result);

	return 0;
}

void *runner(void *param)
{
	int *result = (int *)param;
	int n = result[0];

	printf("Descending Order: \n");

	for(int i = 1; i < n; i++)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if(result[i] < result[j])
			{
				int t = result[i];
				result[i] = result[j];
				result[j] = t;
			}
		}
	}

	for(int i=1;i<n;i++)
		printf("%d ",result[i]);

	printf("\n");

	pthread_exit(0);
}