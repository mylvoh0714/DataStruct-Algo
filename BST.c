#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;


void insertTreeNode(Node** p, int value);
void printTreePreorder(Node* pNode);
void printTreeInorder(Node* pNode);
void printTreePostorder(Node* pNode);

Node* searchTreeNode(Node* p, int value);
Node* searchTreeParentNode(Node* p, int value);
void deleteTreeNode(Node** p, int value);
void copyTreeNode(Node* src, Node** dst);
int compareTwoTree(Node* t1, Node* t2);

int main()
{
	Node* pParentNode = NULL;
	Node* cParentNode = NULL;

	///Insert Data into Tree(pParentNode)
	insertTreeNode(&pParentNode, 4);
	insertTreeNode(&pParentNode, 2);
	insertTreeNode(&pParentNode, 6);
	insertTreeNode(&pParentNode, 1);
	insertTreeNode(&pParentNode, 3);
	insertTreeNode(&pParentNode, 5);
	insertTreeNode(&pParentNode, 7);

	///Print Data in Tree(pParentNode)
	printf("Tree(pParentNode)\n");
	printf("Preorder\t:");
	printTreePreorder(pParentNode);
	printf("\nInorder\t\t:");
	printTreeInorder(pParentNode);
	printf("\nPostorder\t:");
	printTreePostorder(pParentNode);
	printf("\n\n");

	///Search Data in Tree(pParentNode)
	printf("Search Data 3\n");
	if (searchTreeNode(pParentNode, 3) != NULL)
		printf("3 is existed\n\n");
	else
		printf("3 is not existed\n\n");

	///Delete Data in Tree(pParentNode)
	//printf("Delete data 3\n");
	//deleteTreeNode(&pParentNode, 3);
	//printf("Delete data 2\n");
	//deleteTreeNode(&pParentNode, 2);
	printf("Delete data 4\n");
	deleteTreeNode(&pParentNode, 4);

	///Search Data in Tree(pParentNode)
	printf("Search Data 4\n");
	if (searchTreeNode(pParentNode, 4) != NULL)
		printf("4 is existed\n\n");
	else
		printf("4 is not existed\n\n");

	///Print Data in Tree(pParentNode)
	printf("Tree(pParentNode)\n");
	printf("Preorder\t:");
	printTreePreorder(pParentNode);
	printf("\nInorder\t\t:");
	printTreeInorder(pParentNode);
	printf("\nPostorder\t:");
	printTreePostorder(pParentNode);
	printf("\n\n");

	/////Copy Tree(pParentNode) into Tree(cParentNode)
	copyTreeNode(pParentNode, &cParentNode);
	/////Print Data in Tree(cParentNode)
	printf("Preorder\t:");
	printTreePreorder(cParentNode);
	printf("\nInorder\t\t:");
	printTreeInorder(cParentNode);
	printf("\nPostorder\t:");
	printTreePostorder(cParentNode);
	printf("\n\n");

	/////Compare Data between two Trees
	if (compareTwoTree(pParentNode, cParentNode))
		printf("Two trees are equal\n");
	else
		printf("Two trees are different\n");

	return 0;
}


void insertTreeNode(Node** p, int value)
{
	if ((*p) == NULL)
	{
		// Create TreeNode with value
		(*p) = (Node*)malloc(sizeof(Node));
		(*p)->data = value;
		(*p)->leftChild = NULL;
		(*p)->rightChild = NULL;
	}
	else if ((*p)->data > value)
	{
		// Recursive call to leftChild
		insertTreeNode(&((*p)->leftChild), value);
	}
	else
	{
		// Recursive call to rightChild
		insertTreeNode(&((*p)->rightChild), value);
	}
}


void printTreePreorder(Node* pNode)
{
	if (pNode == NULL)
		return;

	printf("%3d", pNode->data);
	printTreePreorder(pNode->leftChild);
	printTreePreorder(pNode->rightChild);
}

void printTreeInorder(Node* pNode)
{
	if (pNode == NULL)
		return;

	printTreeInorder(pNode->leftChild);
	printf("%3d", pNode->data);
	printTreeInorder(pNode->rightChild);
}

void printTreePostorder(Node* pNode)
{
	if (pNode == NULL)
		return;

	printTreePostorder(pNode->leftChild);
	printTreePostorder(pNode->rightChild);
	printf("%3d", pNode->data);
}

Node* searchTreeNode(Node* p, int value)
{
	//p 노드의 데이터가 value와 같을 때까지 탐색
	while (p != NULL && p->data != value)
	{
		//현재 p노드의 데이터와 같지 않을 경우
		//BST의 원리에 맞게 탐색

		if (p->data < value)
			p = p->rightChild;
		else
			p = p->leftChild;
	}
	return p; //찾았으면 해당 노드의 주소를 반환
}

Node* searchTreeParentNode(Node* p, int value)
{
	//p 노드의 직전 노드인 부모 노드 변수
	Node* parentNode = NULL;
	//p 노드의 데이터가 value와 같을 때까지 탐색
	while (p!=NULL && p->data != value)
	{
		// 부모 노드가 p노드를 가리키고
		// p 노드는 다음 자식 노드로 이동
		parentNode = p;
		if (p->data < value)
			p = p->rightChild;
		else
			p = p->leftChild;
	}
	return parentNode;
}


void deleteTreeNode(Node** p, int value)
{
	Node* parentNode; // 지울 노드의 부모 노드
	Node* delNode; // value 값을 갖고 있는 지울 노드
	Node* childNode; // 지울 노드의 자식 노드
	Node* succNode; // Degree 2 노드를 지울 때 필요한 successor 노드
	Node* parentsuccNode = NULL;

	parentNode = searchTreeParentNode(*p, value);
	delNode = searchTreeNode(*p, value);
	if (delNode == NULL)
	{
		printf("There is no %d \n", value);
		return;
	}
	// Case 1. 자식 노드가 하나도 없는 경우
	if (delNode->leftChild == NULL && delNode->rightChild == NULL)
	{
		// 지울 노드가 root 노드인 경우
		if (parentNode == NULL)
		{
			(*p) = NULL;
		}
		else
		{
			// 지울 노드가 부모 노드의 어느 쪽에 있는지 확인하고 NULL로 지정
			if (delNode < parentNode)
				parentNode->leftChild = NULL; // 지울노드가 왼쪽
			else
				parentNode->rightChild = NULL; // 지울노드가 오른쪽
		}
	}
	// Case 2. 자식 노드가 하나 있는 경우
	else if (delNode->leftChild== NULL || delNode->rightChild == NULL)
	{
		//지울 노드의 자식 노드를 childNode 변수를 이용해 가리키도록 함
		childNode = (delNode->leftChild != NULL) ? delNode->leftChild : delNode->rightChild;
		//지울 노드가 root 노드인 경우
		if (parentNode == NULL)
		{
			(*p) = childNode;
		}
		else
		{
			//지울 노드가 부모 노드의 어느 쪽인지 확인하고 자식 노드를 연결
			if (parentNode->leftChild == delNode) // 지울노드가 부모노드의 왼쪽
				parentNode->leftChild = childNode;
			else
				parentNode->rightChild = childNode;
		}
	}
	// Case 3. 자식 노드가 둘 다 있는 경우	.
	else
	{
		//지울 노드의 오른쪽 자식 노드에 접근
		childNode = delNode->rightChild;
		succNode = childNode;

		//지울 노드를 오른쪽 자식 노드에 제일 왼쪽으로 계속 들어가서 지정
		while ( succNode->leftChild != NULL )
		{
			parentsuccNode = succNode;
			succNode = succNode->leftChild;
		}

		// 대체노드의 rightchild가 있으면 부모노드와 연결해주기
		if ( succNode->rightChild != NULL )
			parentsuccNode->leftChild = succNode->rightChild;
		// 없으면 부모노드의 leftchild를 NULL로 지정
		else
			parentsuccNode->leftChild = NULL;


		//지울 노드가 root 노드인 경우
		if ( parentNode == NULL )
		{
			succNode->leftChild = delNode->leftChild;
			succNode->rightChild = delNode->rightChild;
			( *p ) = succNode;
		}
		//지울 노드가 root 노드가 아닌 경우
		else
		{
			// 지울 노드가 부모노드의 leftchild일때
			if ( parentNode->leftChild == delNode )
				parentNode->leftChild = succNode;
			else
				parentNode->rightChild = succNode;

			succNode->leftChild = delNode->leftChild;
			succNode->rightChild = delNode->rightChild;
			( *p ) = succNode;
		}
	}
	free(delNode);
}

void copyTreeNode(Node* src, Node** dst)
{
	if ( !src )
		return;
	insertTreeNode(dst, src->data);
	copyTreeNode(src->leftChild,dst);
	copyTreeNode(src->rightChild,dst);
}

// compareTwoTree는 t1과 t2가 같으면 1, 다르면 0을 반환
int compareTwoTree(Node* t1, Node* t2)
{
	if ( t1 == NULL && t2 == NULL )
		return 1;

	// 세개의 조건식을 모두 만족하면 return 1, 아니면 0 반환
	if ( t1 != NULL && t2 != NULL )
		return t1->data == t2->data && compareTwoTree(t1->leftChild, t2->leftChild) && compareTwoTree(t1->rightChild, t2->rightChild);
	return 0;
}
