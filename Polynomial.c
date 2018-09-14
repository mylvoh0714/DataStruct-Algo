#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode {
	int coef;
	int expon;
	struct polyNode* next;
}polyNode;

void addPolynomial(polyNode** pHeadNode, int coef, int expon);	 //call by reference
void removePolynomial(polyNode** pHeadNode, int expon);
polyNode* multiplication(polyNode* A, polyNode* B);
void showPolynomial(polyNode* pHeadNode);
void clearPolynomial(polyNode** pHeadNode);
int findPolynomial(polyNode* pHeadNode, int expon);

int main()
{
	int mode, coef, expon;
	char poly;
	polyNode *A, *B, *C;
	A = B = C = NULL;

	do
	{
		printf("\nSelect the mode\n");
		printf("=================\n");
		printf("1: add polynomial\n");
		printf("2: remove polynomial\n");
		printf("3: Multiplication\n");
		printf("4: show polynomial\n");
		printf("5: clear polynomial\n");
		printf("-1: exit the program\n");
		printf("==================\n");
		printf("mode: ");
		scanf("%d", &mode);

		switch (mode)
		{
		case 1:
			printf("\nChoose the polynomial to add ('A'or'B')\n");
			printf("Which polynomial?: ");
			scanf(" %c", &poly);
			if (poly != 'A' && poly != 'B')
				printf("Please choose right polynomial (A or B)\n");
			else
			{
				//계수와 차수를 입력 받아서 polynomial에 추가하는 함수 실행
				//이미 존재하는 차수를 입력 받을 경우 추가할 수 없음
				printf("input the coef: ");
				scanf("%d", &coef);
				printf("input the expon: ");
				scanf("%d", &expon);

				if (poly == 'A')
				addPolynomial(&A, coef, expon);
				else // (poly == 'B')
				addPolynomial(&B, coef, expon);
			}
			break;
		case 2:
			printf("\nChoose the polynomial to remove ('A'or'B')\n");
			printf("Which polynomial?: ");
			scanf(" %c", &poly);
			if (poly != 'A' && poly != 'B')
				printf("Please choose right polynomial (A or B)\n");
			else
			{
				printf("input the expon: ");
				scanf("%d", &expon);
				//차수를 입력 받아서 polynomial에서 제거하는 함수 실행
				if (poly == 'A')
					removePolynomial(&A, expon);
				else
					removePolynomial(&B, expon);
			}
			break;
		case 3:
			printf("\nMultiplication with A and B\n");
			//C = A * B 연산을 수행
			C = multiplication(A, B);
			printf("C: ");
			//C의 결과를 출력
			showPolynomial(C);
			break;
		case 4:
			//A,B polynomial 각각 출력
			printf("A: ");
			showPolynomial(A);
			printf("B: ");
			showPolynomial(B);
			break;
		case 5:
			printf("\nChoose the polynomial to clear ('A'or'B')\n");
			printf("Which polynomial?: ");
			scanf(" %c", &poly);
			if (poly != 'A' && poly != 'B')
				printf("Please choose right polynomial (A or B)\n");
			else
				//해당 polynomial를 초기화 시키는 함수 실행
			{
				if (poly == 'A')
					clearPolynomial(&A);
				else
					clearPolynomial(&B);
			}
			break;

		default:
			break;
		}

	} while (mode != -1);


	return 0;
}

void addPolynomial(polyNode** pHeadNode, int coef, int expon)
{
	if (findPolynomial((*pHeadNode), expon) == 0) {
		return;
	}

	polyNode* newNode = (polyNode*)malloc(sizeof(polyNode));
	polyNode* tmpNode = NULL;

	// newNode 초기화
	newNode->coef = coef;
	newNode->expon = expon;
	newNode->next = NULL;

	// 포인터 tmpNode 설정
	tmpNode = (*pHeadNode);


	// newNode 연결
	if (tmpNode == NULL) // 처음인경우
	{
		(*pHeadNode) = newNode;
		return;
	}
	else // 처음아닌경우
	{
		while (tmpNode->next != NULL) // tmpNode 마지막노드까지 이동
			tmpNode = tmpNode->next;
		tmpNode->next = newNode;
	}
}

void removePolynomial(polyNode** pHeadNode, int expon)
{
	// delNode, tmpNode 초기화
	polyNode* delNode ,*tmpNode = NULL;
	tmpNode = (*pHeadNode);

	if (tmpNode == NULL) // 저장되어있는 다항식이 없을경우
	{
		printf("remove할 다항식이 없습니다\n");
		return;
	}
	else if(tmpNode->next == NULL) // 저장되어있는 다항식이 단항식일 경우
	{
		if (tmpNode->expon == expon) {
			delNode = tmpNode;
			free(delNode);
			*pHeadNode = NULL;
			return;
		}
		else {
			printf("remove할 차수가 존재하지 않습니다. 다시 입력해 주세요.\n");
			return;
		}
	}
	else // 저장되어있는 다항식이 다항식일 경우
	{
		// delNode expon 탐색
		while ((tmpNode->next)->expon != expon)
			tmpNode = tmpNode->next;

		// 삭제
		delNode = tmpNode->next;  // 삭제할 노드 = 직전 노드의 next Node
		tmpNode->next = delNode->next; // 직전노드의 next Node = 삭제할노드의 next Node
		free(delNode);
	}
}

polyNode* multiplication(polyNode* A, polyNode* B)
{
	polyNode *C, *Atmp, *Btmp, *tmpNode;
	int coef = 0;

	Atmp = A;
	Btmp = B;
	C = NULL;

	tmpNode = (polyNode *)malloc(sizeof(polyNode));

	while (Atmp != NULL) {
		while (Btmp != NULL) {
			tmpNode->coef = (Btmp->coef) * (Atmp->coef);
			tmpNode->expon = (Btmp->expon) + (Atmp->expon);
			addPolynomial(&C, (tmpNode->coef), (tmpNode->expon));
			Btmp = Btmp->next;
		}
		Atmp = Atmp->next;
		Btmp = B;
	}
	return C;
}


void showPolynomial(polyNode* pHeadNode)
{
	while (pHeadNode != NULL)
	{
		printf("%d*X^%d", pHeadNode->coef, pHeadNode->expon);
		if (pHeadNode->next != NULL) // 뒤에 항이 더 있으면
			printf("+");
		pHeadNode = pHeadNode->next;
	}
	printf("\n====================\n");
}

void clearPolynomial(polyNode** pHeadNode)
{
	polyNode* delNode, *tmpNode = NULL;
	if (*pHeadNode == NULL) {
		printf("clear할 polynomial이 없습니다\n");
		return;
	}
	tmpNode = (*pHeadNode);

	while (tmpNode->next != NULL)
	{
		delNode = tmpNode;
		tmpNode = tmpNode->next;
		free(delNode);
	}
	(*pHeadNode) = NULL;
}

int findPolynomial(polyNode* pHeadNode, int expon)
{
	polyNode *tmpNode = NULL;
	tmpNode = pHeadNode;

	while (tmpNode != NULL) {
		if (tmpNode->expon == expon)
			return 0;
		tmpNode = tmpNode->next;
	}
	return 1;
}
