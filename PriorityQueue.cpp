//2015058204 오현택
#include <stdio.h>
#include <stdlib.h>

void Heapify(int *Array, int current, int heapsize)
{
	int left, right, largest,temp;
	left = 2 * current;
	right = 2 * current + 1;

	if ( ( right <= heapsize ) && ( Array[right]>Array[current] ) )
		largest = right;
	else
		largest = current;

	if ( ( left <= heapsize ) && ( Array[left]>Array[largest] ) )
		largest = left;

	if ( largest != current )
	{
		temp = Array[largest];
		Array[largest] = Array[current];
		Array[current] = temp;
		Heapify(Array, largest, heapsize);
	}
}

int EXTRACT_MAX(int *Array, int heapsize)
{
	int max;
	if ( heapsize < 1 )
		max = Array[1];
	Array[1] = Array[heapsize];
	heapsize--; Heapify(Array, 1, heapsize);
	return max;
}

void INCREASE_KEY(int *Array, int index, int key)
{
	int tmp = 0;

	while ( index>1 && Array[index/2]<Array[index] )
	{
		tmp = Array[index];
		Array[index] = Array[index / 2];
		Array[index / 2] = tmp;
		index = index/2;
	}
}

void INSERT(int *Array, int heapsize, int key)
{
	Array[heapsize] = -9999;
	INCREASE_KEY(Array, heapsize, key);
}



int main(void)
{
	int Array[100000];
	int PopArray[100000];
	int heapsize = 0, popheapsize = 0;

	int op, tmp, i;
	int index, num;

	while ( 1 )
	{
		scanf("%d", &op);
		switch ( op )
		{
		case 0:
			for ( i = 1; i <= popheapsize; i++ )
				printf("%d ", PopArray[i]);

			printf("\n");
			for ( i = 1; i <= heapsize; i++ )
				printf("%d ", Array[i]);

			exit(0);

		case 1:
			scanf("%d", &num);
			heapsize++;
			Array[heapsize] = num;
			INCREASE_KEY(Array, heapsize, num);
			break;

		case 2:
			popheapsize++;
			PopArray[popheapsize] = Array[1];

			tmp = Array[1];
			Array[1] = Array[heapsize];
			Array[heapsize] = tmp;

			heapsize--;
			Heapify(Array, 1, heapsize);
			break;

		case 3:
			scanf("%d %d", &index, &num);
			Array[index] = num;
			if ( index != 1 && Array[index] > Array[index/2] )
				INCREASE_KEY(Array, index, num);
			else
				Heapify(Array, index, heapsize);
			break;

		default:
			break;
		}
	}

	return 0;
}
