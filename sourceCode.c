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
			printf("---------Ӧ��-------");
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
	for (lastNode = MAX_TREE_SIZE - 1; lastNode >= 0; lastNode--)
		if (bt[lastNode] != Nil)
			break;
	lastNode++;
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
			break;
		case 9:
			break;
		default:
			printf("ERROR!");
			break;
		}
	} while (n != 9);
}

void Graph()
{
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
			printf("---------�������ڽӾ���/�ڽӱ�-------");
			break;
		case 2:
			printf("---------���������/��ȣ�-------");
			break;
		case 3:
			printf("---------��λ-------");
			break;
		case 4:
			printf("---------�ҵ�һ���ڽӵ�-------");
			break;
		case 5:
			printf("---------����һ���ڽӵ�-------");
			break;
		case 6:
			printf("---------���루��/�ߣ�-------");
			break;
		case 7:
			printf("---------ɾ������/�ߣ�-------");
			break;
		case 8:
			printf("---------Ӧ��-------");
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
