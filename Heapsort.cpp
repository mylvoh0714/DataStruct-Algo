// 2015058204_¿ÀÇöÅÃ_11736
#include <stdio.h>
#include <stdlib.h>

void Build_Max_Heap(int *Array, int Heapsize);
void Max_Heapify(int *Array,int i, int Heapsize);
void Heapsort(int *Array, int Heapsize);

int main()
{
	int N, k, i, heapsize;
	int* Array;
	scanf("%d", &N);
	scanf("%d", &k);

	Array = (int*)malloc(sizeof(int)*N);
	
	for ( i = 1; i <= N; i++ )
	{
		scanf("%d", &Array[i]);
	}
	
	heapsize = N;
	Heapsort(Array, heapsize);
	for ( i = N; i > N - k; i-- )
		printf("%d ", Array[i]);
	printf("\n");
	for ( i = N-k; i >=1 ; i--	 )
		printf("%d ", Array[i]);

	return 0;
}

void Build_Max_Heap(int *Array, int Heapsize)
{
	int i;
	for ( i = Heapsize / 2; i > 0; i-- )
	{
		Max_Heapify(Array, i, Heapsize);
	}
}

void Max_Heapify(int *Array, int i, int Heapsize)
{
	int temp, largest;
	int leftNode = 2 * i;
	int rightNode = 2 * i + 1;
	if ( ( leftNode <= Heapsize ) && ( Array[leftNode] > Array[i] ) )
		largest = leftNode;
	else
		largest = i;
	
	if ( ( rightNode <= Heapsize ) && Array[rightNode] > Array[largest] )
		largest = rightNode;

	if ( largest != i )
	{
		temp = Array[i];
		Array[i] = Array[largest];
		Array[largest] = temp;
		Max_Heapify(Array, largest, Heapsize);
	}
}

void Heapsort(int *Array, int Heapsize)
{
	int i, temp;
	Build_Max_Heap(Array, Heapsize);
	for ( i = Heapsize; i > 1; i-- )
	{
		temp = Array[i];
		Array[i] = Array[1];
		Array[1] = temp;
		Heapsize--;
		Max_Heapify(Array, 1, Heapsize);
	}
}