#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;
typedef struct Node* LinkList;

void ShowMainMenu()
{
	printf("\n");
	printf("*******************�㷨�����ݽṹ******************\n");
	printf("* 1  ������Ļ���������Ӧ��                       *\n");
	printf("* 2  ջ�Ļ���������Ӧ��                           *\n");
	printf("* 3  ���еĻ���������Ӧ��                         *\n");
	printf("* 4  �������Ļ���������Ӧ��                       *\n");
	printf("* 5  ͼ�Ļ���������Ӧ��                           *\n");
	printf("* 6  �˳�                                         *\n");
	printf("***************************************************\n");
}

void intVisit(int elem)
{
	printf("%d ", elem);
	return;
}

LinkList InitList(LinkList* linkList)
{
	*linkList = (LinkList)malloc(sizeof(Node));
	if (!(*linkList))
		exit(0);
	(*linkList)->next = NULL;
	return *linkList;
}

bool ListEmpty(LinkList linklist)
{
	LinkList currentNodeP = linklist->next;
	if (currentNodeP)
		return false;
	return true;
}

LinkList ClearList(LinkList* linkList)
{
	LinkList currentNodeP, previousNodeP;
	currentNodeP = (*linkList)->next;
	while (currentNodeP)
	{
		previousNodeP = currentNodeP;
		currentNodeP = currentNodeP->next;
		free(previousNodeP);
	}
	(*linkList)->next = NULL;
	return *linkList;
}

int ListLength(LinkList linkList)
{
	LinkList currentNodeP = linkList->next;
	int count = 0;
	while (currentNodeP)
	{
		count++;
		currentNodeP = currentNodeP->next;
	}
	return count;
}

int GetElem(LinkList linkList, int i)
{
	LinkList currentNodeP = linkList;
	int count = 0;
	while (currentNodeP && count < i)
	{
		count++;
		currentNodeP = currentNodeP->next;
	}
	if (!currentNodeP || count > i)
	{
		printf("GetElem�±�Խ�磡����0");
		return 0;
	}
	return currentNodeP->data;
}

int LocateElem(LinkList linkList, int elem)
{
	LinkList currentNodeP = linkList;
	int count = 0;
	while (currentNodeP)
	{
		if (currentNodeP->data == elem)
			return count;
		count++;
		currentNodeP = currentNodeP->next;
	}
	return 0;
}

void ListInsert(LinkList* linkList, int i, int elem)
{
	LinkList currentNodeP, newNodeP;
	currentNodeP = *linkList;
	int count = 0;
	while (currentNodeP && count < i - 1)
	{
		count++;
		currentNodeP = currentNodeP->next;
	}
	if (!currentNodeP || count > i - 1)
	{
		printf("ListInsert�±�Խ�磡");
		return;
	}
	newNodeP = (LinkList)malloc(sizeof(Node));
	if (!newNodeP)
		exit(0);
	newNodeP->data = elem;
	newNodeP->next = currentNodeP->next;
	currentNodeP->next = newNodeP;
}

int ListDelete(LinkList* linkList, int i)
{
	LinkList currentNodeP = *linkList;
	int data = -99999;
	int count = 0;
	while (currentNodeP && count < i - 1)
	{
		count++;
		currentNodeP = currentNodeP->next;
	}
	if (!currentNodeP || count > i - 1)
	{
		printf("ListDelete�±�Խ�磡����0");
		return 0;
	}
	LinkList deleteNodeP = currentNodeP->next;
	currentNodeP->next = deleteNodeP->next;
	data = deleteNodeP->data;
	free(deleteNodeP);
	return data;
}

void ListTraverse(LinkList linkList)
{
	LinkList currentNodeP = linkList->next;
	while (currentNodeP)
	{
		intVisit(currentNodeP->data);
		currentNodeP = currentNodeP->next;
	}
	return;
}

void CreateListHead(LinkList* linkList, int elemNum)
{
	LinkList newNodeP;
	(*linkList) = (LinkList)malloc(sizeof(Node));
	(*linkList)->next = NULL;
	for (int count = 0; count < elemNum; count++)
	{
		newNodeP = (LinkList)malloc(sizeof(Node));
		newNodeP->data = rand() % 100 + 1; // ԭ����stdlib.h��
		newNodeP->next = (*linkList)->next;
		(*linkList)->next = newNodeP;
	}
	return;
}

void CreateListTail(LinkList* linkList, int elemNum)
{
	LinkList tailNodeP, newNodeP;
	(*linkList) = (LinkList)malloc(sizeof(Node));
	(*linkList)->next = NULL;
	tailNodeP = *linkList;
	for (int count = 0; count < elemNum; count++)
	{
		newNodeP = (LinkList)malloc(sizeof(Node));
		newNodeP->data = rand() % 100 + 1;
		tailNodeP->next = newNodeP;
		tailNodeP = newNodeP;
	}
	newNodeP->next = NULL;
}

void UseLinkList()
{
	LinkList list = NULL;
	int index = 0;
	int elem = 0;
	int n = 0;
	do
	{
		printf("\n");
		printf("**************������Ļ���������Ӧ��***************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ����                                         *\n");
		printf("* 3  ɾ��                                         *\n");
		printf("* 4  ����                                         *\n");
		printf("* 5  Ӧ��                                         *\n");
		printf("* 6  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("--------����������---------\n");
			list = InitList(&list);
			CreateListHead(&list, 5);
			printf("list:");
			ListTraverse(list);
			printf("\n������ϣ�\n");
			break;
		case 2:
			printf("--------����Ԫ��-------\n");
			printf("���������±�λ�ã�");
			while (scanf("%d", &index) != 1)
			{
				printf("�±���������͵ģ�\n");
			}
			printf("����Ҫ�����Ԫ�ص�ֵ��");
			while (scanf("%d", &elem) != 1)
			{
				printf("Ԫ�ص�ֵ���������͵ģ�\n");
			}
			ListInsert(&list, index, elem);
			printf("list:");
			ListTraverse(list);
			printf("\n������ϣ�\n");
			break;
		case 3:
			printf("--------ɾ��Ԫ��-------\n");
			printf("����Ҫɾ����Ԫ�ص��±�λ�ã�");
			while (scanf("%d", &index) != 1)
			{
				printf("�±�λ�ñ��������͵ģ�\n");
			}
			ListDelete(&list, index);
			printf("list:");
			ListTraverse(list);
			printf("\nɾ����ϣ�\n");
			break;
		case 4:
			printf("--------����Ԫ��-------\n");
			printf("����Ҫ���ҵ�Ԫ�ص�ֵ��");
			while (scanf("%d", &elem) != 1)
			{
				printf("Ԫ�ص�ֵ���������ͣ�\n");
			}
			index = LocateElem(list, elem);
			printf("��Ԫ����%dλ�á�(0λ�ô����Ҳ�����Ԫ��)\n", index);
			break;
		case 5:
			printf("--------Ӧ��---------\n");
			LinkList list1, list2;
			printf("ͷ�巨����10�����Ԫ�ص�����\n");
			CreateListHead(&list1, 10);
			printf("list1:");
			ListTraverse(list1);
			printf("\nβ�巨����10�����Ԫ�ص�����\n");
			CreateListTail(&list2, 10);
			printf("list2:");
			ListTraverse(list2);
			printf("\nӦ����ϣ�\n");
			break;
		case 6:
			break;
		default:
			printf("ERROR!");
			break;
		}
	} while (n != 6);
}

typedef struct StackNode
{
	int data;
	struct StackNode* next;
} StackNode, * LinkStackPtr;

typedef struct
{
	LinkStackPtr top;
	int count;
} LinkStack;

LinkStack InitStack(LinkStack* stack)
{
	stack->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!stack->top)
		exit(0);
	stack->top = NULL;
	stack->count = 0;
	return *stack;
}

void ClearStack(LinkStack* stack)
{
	LinkStackPtr currentNodePtr, prevNodePtr;
	currentNodePtr = stack->top;
	while (currentNodePtr)
	{
		prevNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->next;
		free(prevNodePtr);
	}
	stack->count = 0;
	return;
}

bool StackEmpty(LinkStack stack)
{
	if (stack.count <= 0)
		return false;
	return true;
}

int StackLength(LinkStack stack)
{
	return stack.count;
}

int GetTop(LinkStack stack)
{
	if (!stack.top)
	{
		printf("���ǿ�ջ��\n");
		exit(0);
	}
	return stack.top->data;
}

void Push(LinkStack* stack, int elem)
{
	LinkStackPtr newNodePtr = (LinkStackPtr)malloc(sizeof(StackNode));
	newNodePtr->data = elem;
	newNodePtr->next = stack->top;
	stack->top = newNodePtr;
	stack->count++;
	return;
}

int Pop(LinkStack* stack)
{
	LinkStackPtr deleteNodePtr = stack->top;
	int data = -99999;
	if (!stack->top)
	{
		printf("���ǿ�ջ��\n");
		exit(0);
	}
	data = stack->top->data;
	stack->top = stack->top->next;
	free(deleteNodePtr);
	stack->count--;
	return data;
}

void StackTraverse(LinkStack stack)
{
	LinkStackPtr currentNodePtr = stack.top;
	for (int i = 0; i < stack.count; i++)
	{
		intVisit(currentNodePtr->data);
		currentNodePtr = currentNodePtr->next;
	}
	printf("\n");
}

#define MAXSIZE 100

typedef struct
{
	int data[MAXSIZE];
	int top1;
	int top2;
} SqDoubleStack;

void visit(int elem)
{
	printf("%d ", elem);
	return;
}

SqDoubleStack InitDoubleStack(SqDoubleStack* stack)
{
	stack->top1 = -1;
	stack->top2 = MAXSIZE;
	return *stack;
}

void ClearDoubleStack(SqDoubleStack* stack)
{
	stack->top1 = -1;
	stack->top2 = MAXSIZE;
	return;
}

bool DoubleStackEmpty(SqDoubleStack stack)
{
	if (stack.top1 == -1 && stack.top2 == MAXSIZE)
		return true;
	return false;
}

int DoubleStackLength(SqDoubleStack stack)
{
	return (MAXSIZE - stack.top2) + (stack.top1 + 1);
}

void DoublePush(SqDoubleStack* stack, int elem, int stackNum)
{
	if (stack->top2 - stack->top1 < 1)
		return;
	else if (1 == stackNum)
		stack->data[++stack->top1] = elem;
	else if (2 == stackNum)
		stack->data[--stack->top2] = elem;

	return;
}

int DoublePop(SqDoubleStack* stack, int stackNum)
{
	if (stack->top1 <= -1 || stack->top2 >= MAXSIZE)
		exit(0);
	else if (1 == stackNum)
		return stack->data[stack->top1--];
	else
		return stack->data[stack->top2++];
}

void DoubleStackTraverse(SqDoubleStack stack)
{
	printf("Stack1: ");
	for (int i = 0; i < stack.top1 + 1; i++)
		visit(stack.data[i]);
	printf("\nStack2: ");
	for (int i = MAXSIZE - 1; i > stack.top2 - 1; i--)
		visit(stack.data[i]);
	printf("\n");
	return;
}

void UseStack()
{
	LinkStack stack = InitStack(&stack);
	int elem = 0;
	int n;
	do
	{
		printf("\n");
		printf("****************ջ�Ļ���������Ӧ��*****************\n");
		printf("* 1  ��ջ                                         *\n");
		printf("* 2  ��ջ                                         *\n");
		printf("* 3  ȡջ��Ԫ��                                   *\n");
		printf("* 4  Ӧ��                                         *\n");
		printf("* 5  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("--------��ջ-------\n");
			printf("stack:");
			StackTraverse(stack);
			printf("�������ջԪ�ص�ֵ��");
			while (scanf("%d", &elem) != 1)
			{
				printf("Ԫ�ص�ֵ���������͵ģ�\n");
			}
			Push(&stack, elem);
			printf("stack:");
			StackTraverse(stack);
			printf("��ջ��ϣ�\n");
			break;
		case 2:
			printf("--------��ջ-------\n");
			printf("stack:");
			StackTraverse(stack);
			elem = Pop(&stack);
			printf("��ջ��\n");
			printf("stack:");
			StackTraverse(stack);
			printf("��ջ��ϣ�\n");
			break;
		case 3:
			printf("--------ȡջ��Ԫ��-------\n");
			printf("stack:");
			StackTraverse(stack);
			elem = GetTop(stack);
			printf("ջ��Ԫ��Ϊ%d��\n", elem);
			printf("ȡջ��Ԫ����ϣ�\n");
			break;
		case 4:
			printf("--------Ӧ��-------\n");
			printf("��ջ����洢�ռ�\n");
			SqDoubleStack doubleStack;
			doubleStack = InitDoubleStack(&doubleStack);
			DoublePush(&doubleStack, 1, 1);
			DoublePush(&doubleStack, 2, 1);
			DoublePush(&doubleStack, 3, 1);
			DoublePush(&doubleStack, 4, 1);
			DoublePush(&doubleStack, 10, 2);
			DoublePush(&doubleStack, 11, 2);
			DoublePush(&doubleStack, 12, 2);
			DoublePush(&doubleStack, 13, 2);
			DoubleStackTraverse(doubleStack);
			printf("Doubleջ�ĳ���Ϊ��%d��\n", DoubleStackLength(doubleStack));
			break;
		case 5:
			break;
		default:
			printf("ERROR!");
			break;
		}
	} while (n != 5);
}

typedef struct Node* QueuePtr;
typedef struct
{
	QueuePtr front, rear;
} LinkQueue;

LinkQueue InitQueue(LinkQueue* lqueue)
{
	lqueue->front = lqueue->rear = (QueuePtr)malloc(sizeof(Node));
	if (!lqueue->front)
		exit(0);
	lqueue->rear->next = NULL;
	return *lqueue;
}

void DestoryQueue(LinkQueue* lqueue)
{
	QueuePtr deleteNodeP = lqueue->front;
	while (deleteNodeP)
	{
		lqueue->front = lqueue->front->next;
		free(deleteNodeP);
		deleteNodeP = lqueue->front;
	}
	return;
}

bool QueueEmpty(LinkQueue lqueue)
{
	if (lqueue.front == lqueue.rear)
		return true;
	return false;
}

int GetHead(LinkQueue lqueue)
{
	if (lqueue.front == lqueue.rear)
	{
		printf("���ǿն��У�\n");
		exit(0);
	}
	return lqueue.front->next->data;
}

int GetTail(LinkQueue lqueue)
{
	QueuePtr currentNodeP = lqueue.front;
	if (lqueue.front == lqueue.rear)
	{
		printf("���ǿն��У�\n");
		exit(0);
	}
	while (currentNodeP->next)
	{
		currentNodeP = currentNodeP->next;
	}
	return currentNodeP->data;
}

void EnQueue(LinkQueue* lqueue, int elem)
{
	QueuePtr newNodeP = (QueuePtr)malloc(sizeof(Node));
	if (!newNodeP)
		exit(0);
	newNodeP->data = elem;
	lqueue->rear->next = newNodeP;
	lqueue->rear = newNodeP;
	newNodeP->next = NULL;
	return;
}

int DeQueue(LinkQueue* lqueue)
{
	QueuePtr deleteNodeP;
	if (lqueue->front == lqueue->rear)
	{
		printf("���ǿն��У�\n");
		exit(0);
	}
	deleteNodeP = lqueue->front->next;
	int data = deleteNodeP->data;
	lqueue->front->next = deleteNodeP->next;
	if (lqueue->rear == deleteNodeP)
		lqueue->rear = lqueue->front;
	free(deleteNodeP);
	return data;
}

void QueueTraverse(LinkQueue lqueue)
{
	QueuePtr currentNodeP = lqueue.front->next;
	while (currentNodeP)
	{
		intVisit(currentNodeP->data);
		currentNodeP = currentNodeP->next;
	}
	printf("\n");
	return;
}

void UseQueue()
{
	LinkQueue queue = InitQueue(&queue);
	int elem = 0;
	int n;
	do
	{
		printf("\n");
		printf("*************���еĻ���������Ӧ��**************\n");
		printf("* 1  ����                                     *\n");
		printf("* 2  ����                                     *\n");
		printf("* 3  ȡ��ͷԪ��                               *\n");
		printf("* 4  ȡ��βԪ��                               *\n");
		printf("* 5  Ӧ��                                     *\n");
		printf("* 6  �˳�                                     *\n");
		printf("***********************************************\n");
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("---------����-------\n");
			printf("queue:");
			QueueTraverse(queue);
			printf("����������Ԫ�ص�ֵ��");
			while (scanf("%d", &elem) != 1)
			{
				printf("Ԫ�ص�ֵ���������͵ģ�\n");
			}
			EnQueue(&queue, elem);
			printf("queue:");
			QueueTraverse(queue);
			printf("������ϣ�\n");
			break;
		case 2:
			printf("---------����-------\n");
			printf("queue:");
			QueueTraverse(queue);
			elem = DeQueue(&queue);
			printf("%dԪ�س��У�\n", elem);
			printf("queue:");
			QueueTraverse(queue);
			printf("������ϣ�\n");
			break;
		case 3:
			printf("---------ȡ��ͷԪ��-------\n");
			printf("queue:");
			QueueTraverse(queue);
			elem = GetHead(queue);
			printf("��ͷԪ��Ϊ%d\n", elem);
			printf("ȡ��ͷԪ����ϣ�\n");
			break;
		case 4:
			printf("---------ȡ��βԪ��-------\n");
			printf("queue:");
			QueueTraverse(queue);
			elem = GetTail(queue);
			printf("��βԪ��Ϊ%d\n", elem);
			printf("ȡ��βԪ����ϣ�\n");
			break;
		case 5:
			printf("---------Ӧ��-------\n");
			printf("���е�Ӧ�ò��֣���ͼ��Breach First Seedgeh�㷨��\n");
			break;
		case 6:
			break;
		default:
			printf("ERROR!");
			break;
		}
	} while (n != 6);
}

#define MAX_TREE_SIZE 255
typedef int SqBiTree[MAX_TREE_SIZE];
// level: ������ڵĲ�
// order: ����ڸò�����
typedef struct
{
	int level, order;
} Position;

int Nil = 0; // ��0Ϊ��ֵ

void InitBiTree(SqBiTree bt)
{
	for (int i = 0; i <= MAX_TREE_SIZE - 1; i++)
		bt[i] = Nil;
	return;
}

void CreateBiTree(SqBiTree bt)
{
	int input = 0;
	int i = 0;
	printf("�������ֵ(0�����ֵ, q����quit)��\n");
	while (1 == scanf("%d", &input) && i < MAX_TREE_SIZE)
	{
		fflush(stdin);
		getchar();
		bt[i] = input;
		if (i != 0 && bt[(i + 1) / 2 - 1] == Nil && bt[i] != Nil)
			return;
		i++;
	}

	while (i < MAX_TREE_SIZE)
	{
		bt[i] = Nil;
		i++;
	}

	return;
}

#define ClearBiTree InitBiTree

bool BiTreeEmpty(SqBiTree bt)
{
	if (bt[0] == Nil)
		return true;
	else
		return false;
}

int BiTreeNodesNum(SqBiTree bt)
{
	int i;
	for (i = 0; bt[i] != Nil; i++)
		;
	return i;
}

int BiTreeDepth(SqBiTree bt)
{
	int lastNode;
	int depth = 0;
	// ��һ��forѭ���ҵ�Tree�����һ������Ϊֹ
	for (lastNode = MAX_TREE_SIZE - 1; lastNode >= 0; lastNode--)
		if (bt[lastNode] != Nil)
			break;
	// ��Ϊ��������0��ʼ,����Ϊ���붨�����1��ʼһ��,�����һ
	lastNode++;
	// ��һ��whileѭ������Tree�����
	while (lastNode >= pow(2, depth))
		depth++;

	return depth;
}

int Root(SqBiTree bt)
{
	if (BiTreeEmpty(bt))
		return Nil;
	else
		return bt[0];
}

// ���ظ�����Ⱥͱ���λ�õĽ��
int Value(SqBiTree bt, Position e)
{
	int index = (int)pow(2, e.level - 1) + e.order - 1;
	return bt[index - 1];
}

// ��������bt��eλ�ø�ֵvalue
void Assign(SqBiTree bt, Position e, int value)
{
	int index = (int)pow(2, e.level - 1) + e.order - 1;
	// �������ֵΪNil���߸ý���˫�׽��ΪNil
	if (value != Nil && bt[index / 2 - 1] == Nil)
		return;
	// �������ֵΪ�� �� �ýڵ��зǿյ��ӽڵ�
	else if (value == Nil && bt[(index - 1) * 2 + 1] != Nil || bt[(index - 1) * 2 + 2] != Nil)
		return;
	bt[index - 1] = value;
	return;
}

// ������bt����,e��bt�е�ĳ�����
// ����e��˫��,�����򷵻�Nil
int Parent(SqBiTree bt, int node)
{
	if (bt[0] == Nil)
		return Nil;
	for (int i = 1; i <= MAX_TREE_SIZE - 1; i++)
		if (bt[i] == node)
			return bt[(i + 1) / 2 - 1];
	return Nil;
}

// ������bt����,e��bt�е�ĳ�����
// ����e������,�����򷵻�Nil
int LeftChild(SqBiTree bt, int node)
{
	if (bt[0] == Nil)
		return Nil;
	for (int i = 0; i <= MAX_TREE_SIZE - 1; i++)
		if (bt[i] == node)
			return bt[(i + 1) * 2 - 1];
	return Nil;
}

// ������bt����,e��bt�е�ĳ�����
// ����e���Һ���,�����򷵻�Nil
int RightChild(SqBiTree bt, int e)
{
	if (bt[0] == Nil)
		return Nil;
	for (int i = 0; i <= MAX_TREE_SIZE - 1; i++)
		if (bt[i] == e)
			return bt[(i + 1) * 2];
	return Nil;
}

// ������bt����,e��bt�е�ĳ�����
// ����e�����ֵ�,�����򷵻�Nil
int LeftSibling(SqBiTree bt, int e)
{
	if (bt[0] == Nil)
		return Nil;
	for (int i = 1; i <= MAX_TREE_SIZE; i++)
		// i��ż��,��ôi-1������,˵��i���Һ���
		if (bt[i] == e && !(i % 2))
			return bt[i - 1];
	return Nil;
}

// ������bt����,e��bt�е�ĳ�����
// ����e�����ֵ�,�����򷵻�Nil
int RightSibling(SqBiTree bt, int e)
{
	if (bt[0] == Nil)
		return Nil;
	for (int i = 1; i <= MAX_TREE_SIZE - 1; i++)
		// i������,��ôi+1��ż��,˵��i������
		if (bt[i] == e && i % 2)
			return bt[i + 1];
	return Nil;
}

// ��PreOrderTraverse����
void PreTraverse(SqBiTree bt, int i)
{
	intVisit(bt[i]);
	if (bt[2 * (i + 1) - 1] != Nil)
		PreTraverse(bt, 2 * (i + 1) - 1);
	if (bt[2 * (i + 1)] != Nil)
		PreTraverse(bt, 2 * (i + 1));
	return;
}
// ǰ������㷨
void PreOrderTraverse(SqBiTree bt)
{
	if (!BiTreeEmpty(bt))
		PreTraverse(bt, 0);
	printf("\n");
	return;
}

// ��InOrderTraverse()����
void InTraverse(SqBiTree bt, int i)
{
	if (bt[2 * (i + 1) - 1] != Nil)
		InTraverse(bt, 2 * (i + 1) - 1);
	intVisit(bt[i]);
	if (bt[2 * (i + 1)] != Nil)
		InTraverse(bt, 2 * (i + 1));
	return;
}
// ��������㷨
void InOrderTraverse(SqBiTree bt)
{
	if (!BiTreeEmpty(bt))
		InTraverse(bt, 0);
	printf("\n");
	return;
}

// ��PostOrderTraverse()����
void PostTraverse(SqBiTree bt, int i)
{
	if (bt[2 * (i + 1) - 1] != Nil)
		PostTraverse(bt, 2 * (i + 1) - 1);
	if (bt[2 * (i + 1)] != Nil)
		PostTraverse(bt, 2 * (i + 1));
	intVisit(bt[i]);
	return;
}
// ��������㷨
void PostOrderTraverse(SqBiTree bt)
{
	if (!BiTreeEmpty(bt))
		PostTraverse(bt, 0);
	printf("\n");
	return;
}

// ��������㷨
void LevelOrderTraverse(SqBiTree bt)
{
	int lastNode;
	for (lastNode = MAX_TREE_SIZE - 1; lastNode >= 0; lastNode--)
		if (bt[lastNode] != Nil)
			break;
	lastNode++;
	for (int i = 0; i < lastNode; i++)
		if (bt[i] != Nil)
			intVisit(bt[i]);
	printf("\n");
}

// ���,������������������
void Print(SqBiTree bt)
{
	Position p;
	int e;
	for (int level = 1; level <= BiTreeDepth(bt); level++)
	{
		printf("LEVEL%d: ", level);
		for (int i = 1; i <= pow(2, level - 1); i++)
		{
			p.level = level;
			p.order = i;
			e = Value(bt, p);
			if (e != Nil)
				printf("[%d]:%d ", i, e);
		}
		printf("\n");
	}
}

typedef enum
{
	Link,  // 0ֵ����Link,��Ϊ��ʹ��
	Thread // 1ֵ����Thread,��Ϊ����ʹ��
} PointerTag;

typedef struct BiThrNode
{
	char data;
	struct BiThrNode* lchild, * rchild;
	PointerTag LTag;
	PointerTag RTag;
} BiThrNode, * BiThrTree;

char _Nil = '#';

void charVisit(char e)
{
	printf("%c ", e);
	return;
}

BiThrTree InitBiThrTree(BiThrTree* btt)
{
	*btt = NULL;
	return *btt;
}

// ��ǰ������㷨��˳��������һ����
void CreateBiThrTree(BiThrTree* btt)
{
	char ch;
	getchar();
	scanf("%c", &ch);
	fflush(stdin);

	if (ch == _Nil)
		*btt = NULL;
	else
	{
		*btt = (BiThrTree)malloc(sizeof(BiThrNode));
		if (!*btt)
			exit(0);
		(*btt)->data = ch;
		CreateBiThrTree(&((*btt)->lchild));
		if ((*btt)->lchild)
			(*btt)->LTag = Link;
		CreateBiThrTree(&((*btt)->rchild));
		if ((*btt)->rchild)
			(*btt)->RTag = Link;
	}
	return;
}

// ȫ�ֱ���,����ָ����һ�����ʹ��Ľ��(����ǰ������λ��)
BiThrTree prevP = NULL;
// �����������������������
void InThreading(BiThrTree currentP)
{
	if (currentP)
	{
		// �����������,��������ҵ�˳��,�ҵ����������
		InThreading(currentP->lchild);
		// ������ߵ�������ʼ���صݹ�,�����ǵݹ�����жԵ�ǰ���������ڵ�Ĳ���
		// �����ý��,��������ָ��ǰ��
		if (!currentP->lchild)
		{
			currentP->LTag = Thread;
			currentP->lchild = prevP;
		}
		// �����ý���ǰ�����,��������ָ�����
		if (!prevP->rchild)
		{
			prevP->RTag = Thread;
			prevP->rchild = currentP;
		}
		// �ý��������,���ڸý���Ϊǰ�����,�ݹ�
		prevP = currentP;
		// ������������ĸ����,��ʼ�ݹ�����������������
		InThreading(currentP->rchild);
	}
	return;
}
// �������������,thrHeadָ��ͷ���,btt�Ƕ���������
void InOrderThreading(BiThrTree* thrHead, BiThrTree btt)
{
	*thrHead = (BiThrTree)malloc(sizeof(BiThrNode));
	if (!*thrHead)
		exit(0);
	// ��ʼ��ͷ����lchild,������Ҫ��ΪLink,ָ������Root
	(*thrHead)->LTag = Link;
	(*thrHead)->lchild = NULL;
	// ��ʼ��ͷ����rchild,������Ҫ��Ϊ����,ָ����������е����һ��Ԫ��
	(*thrHead)->RTag = Thread;
	(*thrHead)->rchild = NULL;
	// ���btt���ǿ���
	if (btt)
	{
		(*thrHead)->lchild = btt;
		// ����������ǰ,��ͷ���Ϊǰһ�����,���䴫��InThreading()��
		prevP = (*thrHead);
		InThreading(btt);
		// ��������������,ȫ�ֱ���prevP�ͳ������һ�����
		prevP->RTag = Thread;
		// ���һ������rchildָ��ͷ���
		prevP->rchild = (*thrHead);
		// ͷ����rchildָ�����һ�����
		(*thrHead)->rchild = prevP;
	}
	return;
}

// �Էǵݹ����ʽ(����ʱ�临�Ӷ�,��Ҳ��������������Ŀ������)
// ����������������btt
void InOrderTraverse_Thr(BiThrTree btt)
{
	BiThrTree currentP;
	currentP = btt->lchild;
	// �Ӹ��ڵ㿪ʼ,�����������ص�ͷ���(��ѭ������һ��)
	// ����ͷ�����Ϊ�ж�ѭ���Ƿ����������
	while (currentP != btt)
	{
		// ���ҵ����������
		while (currentP->LTag == Link)
			currentP = currentP->lchild;
		// ѭ��������,currentPָ�������������ĸ����
		charVisit(currentP->data);
		// �����������Ƿ�����������,���û��,ʹ�������ص�����˫��
		while (currentP->RTag == Thread && currentP->rchild != btt)
		{
			currentP = currentP->rchild;
			charVisit(currentP->data);
		}
		// ʣ�����һ��������ǻ�ʣLink������,��ô����
		currentP = currentP->rchild;
	}
	return;
}

void UseBiTree()
{
	SqBiTree bt;
	int index = 0;
	int value = 0;
	int num = 0;
	int n = 0;
	do
	{
		printf("\n");
		printf("**************�������Ļ���������Ӧ��***************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ��������/��/��                             *\n");
		printf("* 3  �������                                   *\n");
		printf("* 4  ���������                                   *\n");
		printf("* 5  ����˫��                                     *\n");
		printf("* 6  �����ֵܣ���/�ң�                            *\n");
		printf("* 7  ���Һ��ӣ���/�ң�                            *\n");
		printf("* 8  Ӧ��                                         *\n");
		printf("* 9  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("---------����--------\n");
			InitBiTree(bt);
			CreateBiTree(bt);
			printf("������ϣ�\n");
			getchar();
			break;
		case 2:
			printf("---------��������/��/��-------\n");
			printf("ǰ������㷨��");
			PreOrderTraverse(bt);
			printf("\n��������㷨��");
			InOrderTraverse(bt);
			printf("\n��������㷨��");
			PostOrderTraverse(bt);
			printf("\n������ϣ�\n");
			break;
		case 3:
			printf("---------�������-------\n");
			num = BiTreeNodesNum(bt);
			printf("������Ϊ%d\n", num);
			printf("���������ϣ�\n");
			break;
		case 4:
			printf("---------���������-------\n");
			num = BiTreeDepth(bt);
			printf("�������Ϊ%d\n", num);
			printf("�����������ϣ�\n");
			break;
		case 5:
			printf("---------����˫��-------\n");
			printf("����Ҫ���ҵĽ���ֵ��");
			while (scanf("%d", &index) != 1)
			{
				printf("����ֵ���������ͣ�\n");
			}
			value = Parent(bt, index);
			printf("���%d����˫�׵�ֵΪ%d\n", index, value);
			printf("����˫����ϣ�\n");
			break;
		case 6:
			printf("---------�����ֵܣ���/�ң�-------\n");
			printf("����Ҫ���ҵĽ���ֵ��");
			while (scanf("%d", &index) != 1)
			{
				printf("����ֵ���������ͣ�\n");
			}
			value = LeftSibling(bt, index);
			printf("���%d�������ֵܵ�ֵΪ%d\n", index, value);
			value = RightSibling(bt, index);
			printf("���%d�������ֵܵ�ֵΪ%d\n", index, value);
			printf("�����ֵ���ϣ�\n");
			break;
		case 7:
			printf("---------���Һ��ӣ���/�ң�-------\n");
			printf("����Ҫ���ҵĽ���ֵ��");
			while (scanf("%d", &index) != 1)
			{
				printf("����ֵ���������ͣ�\n");
			}
			value = LeftChild(bt, index);
			printf("���%d�������ӵ�ֵΪ%d\n", index, value);
			value = RightChild(bt, index);
			printf("���%d�����Һ��ӵ�ֵΪ%d\n", index, value);
			printf("���Һ�����ϣ�\n");
			break;
		case 8:
			printf("---------Ӧ��-------\n");
			BiThrTree mybtt, header;
			mybtt = InitBiThrTree(&mybtt);
			printf("������������򴴽�һ�Ŷ�������\n");
			CreateBiThrTree(&mybtt);
			printf("������ϡ���������������������\n");
			InOrderThreading(&header, mybtt);
			InOrderTraverse_Thr(header);
			printf("\n");
			break;
		case 9:
			break;
		default:
			printf("ERROR!");
			break;
		}
	} while (n != 9);
}

#define MAXVEX 100
#define INF 65535

typedef struct EdgeNode
{
	int adjvex;
	int weight;
	struct EdgeNode* next;
} EdgeNode;

// Vertexʹ������ṹ
typedef struct VertextNode
{
	char data;
	EdgeNode* firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVexs, numEdges;
} ALGraph;

ALGraph CreateALGraph(ALGraph* graph)
{
	int i, j;       // i��j��������±�
	int weight;     // �ߵ�Ȩֵ
	EdgeNode* edge; // ����·���Ľ��, �嵽������
	printf("���붥������ͱߵĸ�����\n");
	scanf("%d%d", &graph->numVexs, &graph->numEdges);
	// ��AdjList[]�еĸ���VertexNode��data�򸳳�ֵ, ����ʼ��firstedge��ΪNULL
	for (int k = 0; k < graph->numVexs; k++)
	{
		fflush(stdin);
		getchar();
		printf("����%d�����㸳ֵ��\n", k + 1);
		scanf("%c", &graph->adjList[k].data);
		graph->adjList[k].firstedge = NULL;
	}
	// ��numEdges����ָ�������Ľ��, ����Ȩֵ
	for (int k = 0; k < graph->numEdges; k++)
	{
		fflush(stdin);
		printf("�����%d���������ӵ��������㣬�Լ��ߵ�Ȩֵ��\n", k + 1);
		scanf("%d%d%d", &i, &j, &weight);
		// ʹ��ͷ�巨��EdgeNode����VertexNode��
		edge = (EdgeNode*)malloc(sizeof(EdgeNode));
		edge->adjvex = j - 1;
		edge->weight = weight;
		edge->next = graph->adjList[i - 1].firstedge;
		graph->adjList[i - 1].firstedge = edge;
		// ��Ϊ������ͼ,����adjList[i]��adjList[j]Ӧ�û�ָ
		edge = (EdgeNode*)malloc(sizeof(EdgeNode));
		edge->adjvex = i - 1;
		edge->weight = weight;
		edge->next = graph->adjList[j - 1].firstedge;
		graph->adjList[j - 1].firstedge = edge;
	}
	return *graph;
}

// ��־���ʵ�����,������Ǹö����Ƿ��Ѿ������ʹ�
bool visited[MAXVEX];

// ������ȱ����Ĳ���,�������������ȱ�����������
void DFS(ALGraph graph, int i)
{
	// �����÷��ʱ�־Ϊtrue
	visited[i] = true;
	EdgeNode* edge = graph.adjList[i].firstedge;
	visit(graph.adjList[i].data);
	while (edge)
	{
		if (!visited[edge->adjvex])
			DFS(graph, edge->adjvex);
		edge = edge->next;
	}
	return;
}
// ������ȱ���,��Ҫ���������DFS��װ�õĲ���
void DFSTraverse(ALGraph graph)
{
	int i; // ���ʶ�����±����
	// ������visited����ı�־Ϊfalse
	for (i = 0; i < graph.numVexs; i++)
		visited[i] = false;
	for (i = 0; i < graph.numVexs; i++)
		if (!visited[i])
			DFS(graph, i);
	return;
}

void BFSTraverse(ALGraph graph)
{
	int i = 0;      // ���ʶ�����±����
	EdgeNode* edge; // edgeָ��,�ڹ�����ޱ�����ʵ����ʹ��
	LinkQueue queue;    // ������ȶ���
	queue = InitQueue(&queue);
	for (i = 0; i < graph.numVexs; i++)
		visited[i] = false;
	// ����ÿ������,���ҽ��й�����ȱ���
	for (i = 0; i < graph.numVexs; i++)
	{
		if (!visited[i])
		{
			// ����ķ��ʲ���
			visited[i] = true;
			visit(graph.adjList[i].data);
			EnQueue(&queue, i);
			// ������ȱ����ľ������
			while (!QueueEmpty(queue))
			{
				i = DeQueue(&queue);
				edge = graph.adjList[i].firstedge;
				while (edge)
				{
					if (!visited[edge->adjvex])
					{
						visited[edge->adjvex] = true;
						visit(graph.adjList[edge->adjvex].data);
						EnQueue(&queue, edge->adjvex);
					}
					edge = edge->next;
				}
			}
		}
	}
	return;
}

int FindValue(ALGraph graph, char value)
{
	for (int i = 0; i < graph.numVexs; i++)
		if (graph.adjList[i].data == value)
			return i + 1;
	return 0;
}

char FindFirstVex(ALGraph graph)
{
	return graph.adjList[0].data;
}

char FindNextVex(ALGraph graph, char value)
{
	int i;
	for (i = 0; i < graph.numVexs; i++)
		if (graph.adjList[i].data == value)
			break;
	return graph.adjList[i + 1].data;
}

/*
* params:
*	graph: ��Ҫ���붥���ͼ
*	value: ������¶����ֵ
*	idnex: �¶�����Ҫ��һ��ԭ�������ӣ�index�������Ӷ�����±�
*	weight: �����ߵ�Ȩֵ
*/
void InsertVex(ALGraph* graph, char value, int index, int weight)
{
	int num = 1;	// �����������������ӵıߵĸ���
	EdgeNode* insertEdge;

	// ���붥�����
	graph->adjList[graph->numVexs].data = value;
	graph->adjList[graph->numVexs].firstedge = NULL;

	// ����߲���
	if (index < graph->numVexs)
	{
		fflush(stdin);
		getchar();
		// ʹ��ͷ�巨��EdgeNode����VertexNode��
		insertEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
		insertEdge->adjvex = index - 1;
		insertEdge->weight = weight;
		insertEdge->next = graph->adjList[graph->numVexs].firstedge;
		graph->adjList[graph->numVexs].firstedge = insertEdge;
		// ����ͼ��������������
		insertEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
		insertEdge->adjvex = graph->numVexs;
		insertEdge->weight = weight;
		insertEdge->next = graph->adjList[index - 1].firstedge;
		graph->adjList[graph->numVexs].firstedge = insertEdge;
	}

	graph->numVexs++;
	return;
}

// �ڽӾ�������ݽṹ,ʹ���ڽӾ��������ʵ����С�������㷨
typedef struct
{
	char vexs[MAXVEX];
	int edge[MAXVEX][MAXVEX];
	int numVexs, numEdges;
} AMGraph;

AMGraph CreateAMGraph(AMGraph* graph)
{
	int i, j;   // i��j��������±�
	int weight; // �ߵ�Ȩֵ
	printf("���붥������ͱߵĸ�����\n");
	scanf("%d%d", &graph->numVexs, &graph->numEdges);
	// ���������㸳ֵ
	for (int k = 0; k < graph->numVexs; k++)
	{
		printf("����%d�����㸳ֵ��\n", k + 1);
		fflush(stdin);
		getchar();
		scanf("%c", &graph->vexs[k]);
	}
	// �����б�Ĭ�ϸ�ֵΪINF(��Ȩֵ)
	for (int i = 0; i < graph->numVexs; i++)
		for (int j = 0; j < graph->numVexs; j++)
			graph->edge[i][j] = INF;
	// ָ��numEdges���������Ķ���,�Լ�Ȩֵ
	for (int k = 0; k < graph->numEdges; k++)
	{
		printf("�����%d���������ӵ��������㣬�Լ��ߵ�Ȩֵ��\n", k + 1);
		fflush(stdin);
		scanf("%d%d%d", &i, &j, &weight);
		graph->edge[i - 1][j - 1] = weight;
		graph->edge[j - 1][i - 1] = graph->edge[i - 1][j - 1];
	}
	return *graph;
}

// �ֶ�����һ��ͼ�Ĺ��̹��ڸ��ӣ��ʷ�װһ��Ĭ�ϵ��ڽӾ������ɹ����ڸú�����
void _CreateAMGraph(AMGraph* G)
{
	int i, j;

	/* printf("����������Ͷ�����:"); */
	G->numEdges = 15;
	G->numVexs = 9;

	for (i = 0; i < G->numVexs; i++)/* ��ʼ��ͼ */
	{
		for (j = 0; j < G->numVexs; j++)
		{
			if (i == j)
				G->edge[i][j] = 0;
			else
				G->edge[i][j] = G->edge[j][i] = INF;
		}
	}

	G->edge[0][1] = 10;
	G->edge[0][5] = 11;
	G->edge[1][2] = 18;
	G->edge[1][8] = 12;
	G->edge[1][6] = 16;
	G->edge[2][8] = 8;
	G->edge[2][3] = 22;
	G->edge[3][8] = 21;
	G->edge[3][6] = 24;
	G->edge[3][7] = 16;
	G->edge[3][4] = 20;
	G->edge[4][7] = 7;
	G->edge[4][5] = 26;
	G->edge[5][6] = 17;
	G->edge[6][7] = 19;

	for (i = 0; i < G->numVexs; i++)
	{
		for (j = i; j < G->numVexs; j++)
		{
			G->edge[j][i] = G->edge[i][j];
		}
	}
}

// Prim�㷨������С������(Minumum Cost Spanning Tree)
void MiniSpanTree_Prim(AMGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		/* ������ض����±� */
	int lowcost[MAXVEX];	/* ������ض����ߵ�Ȩֵ */
	lowcost[0] = 0;/* ��ʼ����һ��ȨֵΪ0����v0���������� */
			/* lowcost��ֵΪ0����������Ǵ��±�Ķ����Ѿ����������� */
	adjvex[0] = 0;			/* ��ʼ����һ�������±�Ϊ0 */
	for (i = 1; i < G.numVexs; i++)	/* ѭ�����±�Ϊ0���ȫ������ */
	{
		lowcost[i] = G.edge[0][i];	/* ��v0������֮�бߵ�Ȩֵ�������� */
		adjvex[i] = 0;					/* ��ʼ����Ϊv0���±� */
	}
	for (i = 1; i < G.numVexs; i++)
	{
		min = INF;	/* ��ʼ����СȨֵΪ�ޣ� */
						/* ͨ������Ϊ�����ܵĴ�������32767��65535�� */
		j = 1; k = 0;
		while (j < G.numVexs)	/* ѭ��ȫ������ */
		{
			if (lowcost[j] != 0 && lowcost[j] < min)/* ���Ȩֵ��Ϊ0��ȨֵС��min */
			{
				min = lowcost[j];	/* ���õ�ǰȨֵ��Ϊ��Сֵ */
				k = j;			/* ����ǰ��Сֵ���±����k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);/* ��ӡ��ǰ�������Ȩֵ��С�ı� */
		lowcost[k] = 0;/* ����ǰ�����Ȩֵ����Ϊ0,��ʾ�˶����Ѿ�������� */
		for (j = 1; j < G.numVexs; j++)	/* ѭ�����ж��� */
		{
			if (lowcost[j] != 0 && G.edge[k][j] < lowcost[j])
			{/* ����±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ */
				lowcost[j] = G.edge[k][j];/* ����С��Ȩֵ����lowcost��Ӧλ�� */
				adjvex[j] = k;				/* ���±�Ϊk�Ķ������adjvex */
			}
		}
	}
}

void Graph()
{
	ALGraph graph;
	AMGraph matrix;
	char vexValue;
	int index;
	int weight;
	int n;
	do
	{
		printf("\n");
		printf("****************ͼ�Ļ���������Ӧ��*****************\n");
		printf("* 1  �������ڽӾ���/�ڽӱ�                      *\n");
		printf("* 2  ���������/��ȣ�                            *\n");
		printf("* 3  ��λ                                         *\n");
		printf("* 4  �ҵ�һ���ڽӵ�                               *\n");
		printf("* 5  ����һ���ڽӵ�                               *\n");
		printf("* 6  ���루��/�ߣ�                                *\n");
		printf("* 7  ɾ������/�ߣ�                                *\n");
		printf("* 8  Ӧ��                                         *\n");
		printf("* 9  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("---------�������ڽӾ���/�ڽӱ�-------\n");
			graph = CreateALGraph(&graph);
			printf("�����ڽӱ���ϣ�\n");
			break;
		case 2:
			printf("---------���������/��ȣ�-------\n");
			printf("������ȱ�����\n");
			DFSTraverse(graph);
			printf("\n������ȱ�����\n");
			BFSTraverse(graph);
			printf("\n����������\n");
			break;
		case 3:
			printf("---------��λ-------\n");
			printf("�����붥���ֵ��\n");
			getchar();
			while (scanf("%c", &vexValue) != 1)
			{
				fflush(stdin);
				getchar();
				printf("�������ַ���ֵ��\n");
			}
			index = FindValue(graph, vexValue);
			printf("��λ���Ϊ%d��0�����Ҳ����ö��㣩��\n", index);
			printf("��λ������\n");
			break;
		case 4:
			printf("---------�ҵ�һ���ڽӵ�-------\n");
			vexValue = FindFirstVex(graph);
			printf("��һ���ڽӵ��ֵΪ%c��\n", vexValue);
			printf("������ϣ�\n");
			break;
		case 5:
			printf("---------����һ���ڽӵ�-------\n");
			printf("����ֵ�����Ҹ�ֵ��Ӧ�������һ���ڽӵ㣺\n");
			getchar();
			while (scanf("%c", &vexValue) != 1)
			{
				fflush(stdin);
				getchar();
				printf("�������ַ���ֵ��\n");
			}
			vexValue = FindNextVex(graph, vexValue);
			printf("��һ���ڽӵ��ֵΪ%c��\n", vexValue);
			printf("������ϣ�\n");
			break;
		case 6:
			printf("---------���루��/�ߣ�-------\n");
			printf("���������Ķ����ֵ��\n");
			getchar();
			while (scanf("%c", &vexValue) != 1)
			{
				fflush(stdin);
				printf("�������ַ���ֵ��\n");
			}
			printf("�������������ӵĶ�����±��Ȩֵ��#�����˳�����\n");
			getchar();
			scanf("%d%d", &index, &weight);
			InsertVex(&graph, vexValue, index, weight);
			printf("�������ϣ�\n");
			break;
		case 7:
			printf("---------ɾ������/�ߣ�-------\n");
			printf("����ɾ���Ķ�����±꣺\n");
			while (scanf("%d", &index) != 1 && index > graph.numVexs)
			{
				printf("�������룡\n");
			}
			graph.adjList[index - 1].data = -INF;
			printf("ɾ������ϣ�\n");
			break;
		case 8:
			printf("---------Ӧ��-------\n");
			printf("ʹ���ڽӾ���ʵ����С�������㷨\n");
			_CreateAMGraph(&matrix);
			MiniSpanTree_Prim(matrix);
			printf("ʵ����ϣ�\n");
			break;
		case 9:
			break;
		default:
			printf("ERROR!");
			break;
		}
	} while (n != 9);
}

void main(void)
{
	int n;
	do
	{
		ShowMainMenu();
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			UseLinkList();
			break;
		case 2:
			UseStack();
			break;
		case 3:
			UseQueue();
			break;
		case 4:
			UseBiTree();
			break;
		case 5:
			Graph();
			break;
		case 6:
			break;
		default:
			printf("ERROR!");
			break;
		}
	} while (n != 6);
	return;
}
