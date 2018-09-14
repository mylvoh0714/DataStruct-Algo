// 2015058204_오현택_11736
#include <stdio.h>
#include <stdlib.h>

void MergeSort(int arr[], int temp[], int left, int right);
void Merge(int arr[], int temp[], int left, int mid, int right);
void printArray_d_order(int arr[], int n);

int main()
{
	int N, input;
	int *Array, *temp;
	printf("The number of INPUT keys N ?\n");
	scanf("%d", &N);
	Array = (int*)malloc(sizeof(int)*N);
	temp = (int*)malloc(sizeof(int)*N);
	for ( int i = 0; i < N; i++ )
	{
		printf("input the number\n");
		scanf("%d", &input);
		Array[i] = input;
	}

	MergeSort(Array, temp, 1, N);
	printArray_d_order(Array, N);
	free(Array);
	free(temp);
	return 0;
}

void MergeSort(int arr[], int temp[], int left, int right)
{
	int mid = ( left + right ) / 2;
	if ( left < right )
	{
		MergeSort(arr, temp, left, mid);
		MergeSort(arr, temp, mid + 1, right);
		Merge(arr, temp, left, mid, right);
	}
}

void Merge(int arr[], int temp[], int left, int mid, int right)
{

	int i, j, k, l;
	i = left; j = mid + 1, k = right;

	while ( i <= mid && j <= right )
	{
		if ( arr[i] <= arr[j] )
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while ( i <= mid )
		temp[k++] = arr[i++];
	while ( j <= right )
		temp[k++] = arr[j++];

	for ( l = left; l <= right; l++ )
		arr[l] = temp[l];
}

void printArray_d_order(int arr[], int n)
{
	int i;
	for ( i = 0; i < n; i++ )
		printf("%d\n", arr[n - 1 - i]);
}
