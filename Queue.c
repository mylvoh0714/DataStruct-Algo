#include <stdio.h>
#include <stdlib.h>

#define Capacity 5
#define TRUE 1
#define FALSE 0

//Circular Queue 구조체 선언
typedef struct circularQueue {
	int data[Capacity]; // Array List data 선언
	int front; // Circular Queue의 앞부분
	int rear; // Circular Queue의 마지막 부분
}cQueue;

//Circular Queue 관련 함수
cQueue* createCircularQueue();
void enqueue(cQueue** cQueue, int data);
int isFull(cQueue* cQueue);
void showQueue(cQueue* cQueue);
int isEmpty(cQueue* cQueue);
void dequeue(cQueue** cQueue);

int main()
{
	cQueue* cQueue;
	//Circular Queue 초기화
	cQueue = createCircularQueue();
	printf("front:%d, read:%d\n", cQueue->front, cQueue->rear);
	enqueue(&cQueue, 10);
	enqueue(&cQueue, 20);
	enqueue(&cQueue, 30);

	showQueue(cQueue);
	printf("front:%d, read:%d\n", cQueue->front, cQueue->rear);

	dequeue(&cQueue);
	dequeue(&cQueue);

	showQueue(cQueue);
	printf("front:%d, read:%d\n", cQueue->front, cQueue->rear);

	printf("enqueue data 40\n");
	enqueue(&cQueue, 40);
	printf("front:%d, read:%d\n", cQueue->front, cQueue->rear);

	printf("enqueue data 50\n");
	enqueue(&cQueue, 50);
	printf("front:%d, read:%d\n", cQueue->front, cQueue->rear);

	printf("enqueue data 60\n");
	enqueue(&cQueue, 60);
	printf("front:%d, read:%d\n", cQueue->front, cQueue->rear);

	printf("enqueue data 70\n");
	enqueue(&cQueue, 70);
	printf("front:%d, read:%d\n", cQueue->front, cQueue->rear);

	return 0;
}

cQueue* createCircularQueue()
{
	cQueue* pCQueue = NULL;
	// 메모리상에 Queue를 할당시키고 이를 반환
	pCQueue = (cQueue*)malloc(sizeof(cQueue));
	pCQueue->front = 0;
	pCQueue->rear = 0;

	return pCQueue;
}

void enqueue(cQueue** cQueue, int data)
{
	if (isFull(*cQueue) == TRUE)
	{
		printf("Circular Queue is FULL!\n");
		return;
	}
	//Circular Queue의 뒷부분에 data를 추가
	(*cQueue)->rear = ((*cQueue)->rear + 1) % Capacity;
	(*cQueue)->data[(*cQueue)->rear] = data;
}

int isFull(cQueue* cQueue)
{
	if ((cQueue->rear + 1) % Capacity == cQueue->front)
		return TRUE;
	else
		return FALSE;
}

void showQueue(cQueue* cQueue)
{
	if (isEmpty(cQueue) == TRUE)
	{
		printf("Circular Queue is Empty!\n");
		return;
	}
	for (int i = cQueue->front + 1; i <= cQueue->rear; i++)
		printf("[%d]\n", cQueue->data[i]);
	printf("=============================\n");
}

int isEmpty(cQueue* cQueue)
{
	if ((cQueue->rear) % Capacity == cQueue->front)
		return TRUE;
	else
		return FALSE;
}

void dequeue(cQueue** cQueue)
{
	if (isEmpty(*cQueue) == TRUE)
	{
		printf("Circular Queue is Empty!\n");
		return;
	}
	//Circular Queue의 앞 부분을 다음 칸으로 이동
	(*cQueue)->front = ((*cQueue)->front + 1) % Capacity;
}
