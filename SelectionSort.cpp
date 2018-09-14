// 2015058204_오현택_11736
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, input, i,j,temp,least;
	int* Array;
	scanf("%d", &N);
	scanf("%d", &M);

	Array = (int*)malloc(sizeof(int)*N);

	for ( i = 0; i < N; i++ )
	{
		scanf("%d", &input);
		Array[i] = input;
	}

	for ( i = 0; i < M; i++ )
	{
		least = i;
		for ( j = i+1; j < N; j++ )
		{
			if ( Array[j] < Array[least] )
				least = j;
		}
		temp = Array[i];
		Array[i] = Array[least];
		Array[least] = temp;
	}

	for ( i = 0; i < N; i++ )
		printf("%d\n", Array[i]);
	free(Array);
	return 0;
}
