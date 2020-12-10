#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void *runner(void *param);

int main(int argc, char const *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	if (argc < 3)
	{
		fprintf(stderr, "Usage: ./a.out <key> <element_1> <element_2> ...\n");
		return -1;
	}

	int key = atoi(argv[1]);
	int n = argc - 2;
	int *result = (int *)malloc(n * sizeof(int *));

	result[0] = n;
	result[1] = key;

	for (int i = 2; i < argc; i++)
	{
		result[i] = atoi(argv[i]);
	}

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, result);
	pthread_join(tid, NULL);

	for (int i = 0; i < n - 2; i++)
		result[i] = result[i+2];

	sort(result, result+n/2);
	
	int beg = 0;
	int end = n/2-1;
	int flag = 0;
	int c = 0;

	while (beg <= end)
	{
		int mid = (beg+end) / 2;

		if (key == result[mid])
		{
			c++;

			for(int i = mid+1; i<= end; i++)
			{
	      		if(result[i] == key)
	        		c++;

	      		else
	        		break;
	        }

    		for(int i = mid-1; i >= beg; i--)
    		{
	      		if(result[i] == key)
	        		c++;

	      		else
	        		break;
	        }

	    	break;
		}

		else if (key < result[mid])
			end = mid - 1;

		else
			beg = mid + 1;
	}

	printf("Element %d found %d times in the first half.\n", key, c);

	return 0;
}

void *runner(void *param)
{
	int *result = (int *)param;
	int n = result[0], key = result[1];
	int c = 0;

	for (int i = 0; i < n - 2; i++)
		result[i] = result[i+2];

	sort(result+n/2, result+n);
	
	int beg = n/2;
	int end = n-1;
	int flag = 0;

	while (beg <= end)
	{
		int mid = (beg+end) / 2;

		if (key == result[mid])
		{
			c++;

			for(int i = mid+1; i<= end; i++)
			{
	      		if(result[i] == key)
	        		c++;

	      		else
	        		break;
	        }

    		for(int i = mid-1; i >= beg; i--)
    		{
	      		if(result[i] == key)
	        		c++;

	      		else
	        		break;
	        }

	    	break;
		}

		else if (key < result[mid])
			end = mid - 1;

		else
			beg = mid + 1;
	}

	printf("Element %d found %d times in the second half.\n", key, c);

	pthread_exit(0);
}