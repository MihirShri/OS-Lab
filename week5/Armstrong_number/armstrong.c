#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *runner(void *param);

int main(int argc, char const *argv[])
{
	int n;
	pthread_t tid;
	pthread_attr_t attr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./a.out <integer value>\n");
		return -1;
	}

	n = atoi(argv[1]);

	if (n < 0)
	{
		fprintf(stderr, "%d must be >= 0\n", n);
		return -1;
	}

	for (int i = 1; i <= n; i++)
	{
		int *result = (int *)malloc(2*sizeof(int *));
		int num = i, d, cube = 0;

		while (num > 0)
		{
			d = num % 10;
			cube += d * d * d;
			num /= 10;
		}

		result[0] = i;
		result[1] = cube;

		pthread_attr_init(&attr);
		pthread_create(&tid, NULL, runner, (void *)result);
		pthread_join(tid, NULL);
		free(result);
	}

	return 0;
}

void *runner(void *param)
{
	int *result = (int *)param;

	if (result[0] == result[1])
		printf("%d\n", result[0]);

	pthread_exit(0);
}