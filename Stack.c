#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//Stack 구조체 선언 (Linked List)
typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode;

//Stack 관련 함수
StackNode* createLinkedStack();
void pushLinkedStack(StackNode** top, int data);
StackNode* popLinkedStack(StackNode** top);
void showLinkedStack(StackNode* top);
StackNode* topLinkedStack(StackNode* top);
void deleteLinkedStact(StackNode** top);
int isEmpty(StackNode* top);

int main()
{
	//가장 윗 부분을 가리키는 top 포인터 선언
	StackNode* top = NULL;
	StackNode* pNode;

	//Stack 초기화 부분
	top = createLinkedStack();
	if (top == NULL) return -1;
	printf("Push() called.\n");
	pushLinkedStack(&top, 10);
	pushLinkedStack(&top, 20);
	pushLinkedStack(&top, 30);
	showLinkedStack(top);

	printf("Pop() called.\n");
	pNode = popLinkedStack(&top);
	if (pNode)
	{
		free(pNode);
		showLinkedStack(top);
	}

	printf("Top() called. \n");
	pNode = topLinkedStack(top);
	if (pNode)
		printf("Top node's data: %d\n", pNode->data);
	else
		printf("The Stack is empty\n");
	showLinkedStack(top);

	deleteLinkedStact(&top);
	return 0;
}

// Stack 초기화 함수
StackNode* createLinkedStack()
{
	StackNode *topNode = NULL;

	//메모리상에 Stack Node를 할당시키고 이를 반환
	topNode = (StackNode*)malloc(sizeof(StackNode));
	topNode->data = 0;
	topNode->next = NULL;

	return topNode;
}

// 데이터를 추가하여 top에 위치시킴
void pushLinkedStack(StackNode** top, int data)
{
	StackNode* pNode = NULL;

	//넣을 Stack Node를 할당하고 data값을 저장
	pNode = (StackNode*)malloc(sizeof(StackNode));
	pNode->data = data;
	pNode->next = (*top); // tmpNode(pNode)의 next가 top을 가리키게 함
	(*top) = pNode; // top이 tmpNode를 가리키게 함
}

// top이 가리키고 있는 데이터를 삭제
StackNode* popLinkedStack(StackNode** top)
{
	StackNode *pNode = NULL;

	if (isEmpty(*top))
	{
		printf("the Stack is empty\n");
		return NULL;
	}

	//top이 가리키는 Stack Node가 지워지고 다음 Node를 가리키도록 함
	pNode = *top;
	*top = pNode->next;
	pNode->next = NULL;
	return pNode;
}

// top부터 stack의 끝 Node까지 data를 출력
void showLinkedStack(StackNode* top)
{
	StackNode *pNode = NULL;
	if (isEmpty(top))
	{
		printf("the Stack is empty\n");
		return;
	}

	pNode = top;
	while (pNode != NULL)
	{
		printf("[%d]\n", pNode->data);
		pNode = pNode->next;
	}
	printf("=========================\n");
}

// top이 가리키고 있는 데이터를 반환
StackNode* topLinkedStack(StackNode* top)
{
	StackNode *pNode = NULL;

	if (!isEmpty(top))
		pNode = top;
	return pNode;
}

// top부터 stack의 끝 Node까지 메모리 해제
void deleteLinkedStact(StackNode** top)
{

	StackNode* pNode = *top;
	StackNode* pDelNode = NULL;
	while (pNode)
	{
		pDelNode = pNode;
		pNode = pNode->next;
		free(pDelNode);
	}
	*top = NULL;

}

int isEmpty(StackNode* top)
{
	if (top == NULL)
		return TRUE;
	else
		return FALSE;
}
