#include <stdio.h>
#include <stdlib.h>

int list[10] = { 998,586,32,768,720,133,24,700,128,256 };
int radixArray[10][11];

void radixSort(int list[])
{
	int i, j, k, cnt;
	int index, number = 1;
	for ( i = 0; i < 3; i++ )
	{
		//radix array 초기화
		for ( j = 0; j < 10; j++ )
		{
			radixArray[j][0] = 1;
			for ( k = 1; k < 11; k++ )
				radixArray[i][k] = 0;
		}
		//list 원소들의 자리수 값을 뽑아내어 radix array에 저장
		for ( j = 0; j < 10; j++ )
		{
			// number가 1일땐 1의자리, number가 10일땐 10의자리, number가 100일땐 100의자리가 나옴.
			index = ( list[j] / number ) % 10;
			radixArray[index][radixArray[index][0]] = list[j];
			radixArray[index][0] ++;
		}

		// 각 iteration마다 결과를 list에 update
		cnt = 0;
		for ( j = 0; j < 10; j++ )
		{
			for ( k = 1; k < radixArray[j][0]; k++ )
				list[cnt++] = radixArray[j][k];
		}
		printf("%d차:\t", i + 1);
		for ( j = 0; j < 10; j++ )
			printf("%d\t", list[j]);
		printf("\n");

		number *= 10;
	}
}

int main()
{
	int i;
	printf("초기:\t");
	for ( i = 0; i < 10; i++ )
		printf("%d\t", list[i]);
	printf("\n\n");

	radixSort(list);

	printf("\n결과:\t");
	for ( i = 0; i < 10; i++ )
		printf("%d\t", list[i]);
	printf("\n");

	return 0;
}
