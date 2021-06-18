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
	printf("*******************算法与数据结构******************\n");
	printf("* 1  单链表的基本操作及应用                       *\n");
	printf("* 2  栈的基本操作及应用                           *\n");
	printf("* 3  队列的基本操作及应用                         *\n");
	printf("* 4  二叉树的基本操作及应用                       *\n");
	printf("* 5  图的基本操作及应用                           *\n");
	printf("* 6  退出                                         *\n");
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
		printf("GetElem下标越界！返回0");
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
		printf("ListInsert下标越界！");
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
		printf("ListDelete下标越界！返回0");
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
		newNodeP->data = rand() % 100 + 1; // 原型在stdlib.h中
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
		printf("**************单链表的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  插入                                         *\n");
		printf("* 3  删除                                         *\n");
		printf("* 4  查找                                         *\n");
		printf("* 5  应用                                         *\n");
		printf("* 6  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("--------创建单链表---------\n");
			list = InitList(&list);
			CreateListHead(&list, 5);
			printf("list:");
			ListTraverse(list);
			printf("\n创建完毕！\n");
			break;
		case 2:
			printf("--------插入元素-------\n");
			printf("输入插入的下标位置：");
			while (scanf("%d", &index) != 1)
			{
				printf("下标必须是整型的！\n");
			}
			printf("输入要插入的元素的值：");
			while (scanf("%d", &elem) != 1)
			{
				printf("元素的值必须是整型的！\n");
			}
			ListInsert(&list, index, elem);
			printf("list:");
			ListTraverse(list);
			printf("\n插入完毕！\n");
			break;
		case 3:
			printf("--------删除元素-------\n");
			printf("输入要删除的元素的下标位置：");
			while (scanf("%d", &index) != 1)
			{
				printf("下标位置必须是整型的！\n");
			}
			ListDelete(&list, index);
			printf("list:");
			ListTraverse(list);
			printf("\n删除完毕！\n");
			break;
		case 4:
			printf("--------查找元素-------\n");
			printf("输入要查找的元素的值：");
			while (scanf("%d", &elem) != 1)
			{
				printf("元素的值必须是整型！\n");
			}
			index = LocateElem(list, elem);
			printf("该元素在%d位置。(0位置代表找不到该元素)\n", index);
			break;
		case 5:
			printf("--------应用---------\n");
			LinkList list1, list2;
			printf("头插法建立10个随机元素的链表：\n");
			CreateListHead(&list1, 10);
			printf("list1:");
			ListTraverse(list1);
			printf("\n尾插法建立10个随机元素的链表：\n");
			CreateListTail(&list2, 10);
			printf("list2:");
			ListTraverse(list2);
			printf("\n应用完毕！\n");
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
		printf("这是空栈！\n");
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
		printf("这是空栈！\n");
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
		printf("****************栈的基本操作及应用*****************\n");
		printf("* 1  进栈                                         *\n");
		printf("* 2  出栈                                         *\n");
		printf("* 3  取栈顶元素                                   *\n");
		printf("* 4  应用                                         *\n");
		printf("* 5  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("--------进栈-------\n");
			printf("stack:");
			StackTraverse(stack);
			printf("请输入进栈元素的值：");
			while (scanf("%d", &elem) != 1)
			{
				printf("元素的值必须是整型的！\n");
			}
			Push(&stack, elem);
			printf("stack:");
			StackTraverse(stack);
			printf("进栈完毕！\n");
			break;
		case 2:
			printf("--------出栈-------\n");
			printf("stack:");
			StackTraverse(stack);
			elem = Pop(&stack);
			printf("出栈后：\n");
			printf("stack:");
			StackTraverse(stack);
			printf("出栈完毕！\n");
			break;
		case 3:
			printf("--------取栈顶元素-------\n");
			printf("stack:");
			StackTraverse(stack);
			elem = GetTop(stack);
			printf("栈顶元素为%d。\n", elem);
			printf("取栈顶元素完毕！\n");
			break;
		case 4:
			printf("--------应用-------\n");
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
		printf("这是空队列！\n");
		exit(0);
	}
	return lqueue.front->next->data;
}

int GetTail(LinkQueue lqueue)
{
	QueuePtr currentNodeP = lqueue.front;
	if (lqueue.front == lqueue.rear)
	{
		printf("这是空队列！\n");
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
		printf("这是空队列！\n");
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
		printf("*************队列的基本操作及应用**************\n");
		printf("* 1  入列                                     *\n");
		printf("* 2  出列                                     *\n");
		printf("* 3  取队头元素                               *\n");
		printf("* 4  取队尾元素                               *\n");
		printf("* 5  应用                                     *\n");
		printf("* 6  退出                                     *\n");
		printf("***********************************************\n");
		printf("请选择：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("---------入列-------\n");
			printf("queue:");
			QueueTraverse(queue);
			printf("请输入入列元素的值：");
			while (scanf("%d", &elem) != 1)
			{
				printf("元素的值必须是整型的！\n");
			}
			EnQueue(&queue, elem);
			printf("queue:");
			QueueTraverse(queue);
			printf("入列完毕！\n");
			break;
		case 2:
			printf("---------出列-------\n");
			printf("queue:");
			QueueTraverse(queue);
			elem = DeQueue(&queue);
			printf("%d元素出列！\n", elem);
			printf("queue:");
			QueueTraverse(queue);
			printf("出列完毕！\n");
			break;
		case 3:
			printf("---------取队头元素-------\n");
			printf("queue:");
			QueueTraverse(queue);
			elem = GetHead(queue);
			printf("队头元素为%d\n", elem);
			printf("取队头元素完毕！\n");
			break;
		case 4:
			printf("---------取队尾元素-------\n");
			printf("queue:");
			QueueTraverse(queue);
			elem = GetTail(queue);
			printf("队尾元素为%d\n", elem);
			printf("取队尾元素完毕！\n");
			break;
		case 5:
			printf("---------应用-------");
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
// level: 结点所在的层
// order: 结点在该层的序号
typedef struct
{
	int level, order;
} Position;

int Nil = 0; // 以0为空值

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
	printf("输入结点的值(0代表空值, q代表quit)：\n");
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

// 返回给定深度和本层位置的结点
int Value(SqBiTree bt, Position e)
{
	int index = (int)pow(2, e.level - 1) + e.order - 1;
	return bt[index - 1];
}

// 给二叉树bt的e位置赋值value
void Assign(SqBiTree bt, Position e, int value)
{
	int index = (int)pow(2, e.level - 1) + e.order - 1;
	// 如果输入值为Nil或者该结点的双亲结点为Nil
	if (value != Nil && bt[index / 2 - 1] == Nil)
		return;
	// 如果输入值为空 且 该节点有非空的子节点
	else if (value == Nil && bt[(index - 1) * 2 + 1] != Nil || bt[(index - 1) * 2 + 2] != Nil)
		return;
	bt[index - 1] = value;
	return;
}

// 二叉树bt存在,e是bt中的某个结点
// 返回e的双亲,若无则返回Nil
int Parent(SqBiTree bt, int node)
{
	if (bt[0] == Nil)
		return Nil;
	for (int i = 1; i <= MAX_TREE_SIZE - 1; i++)
		if (bt[i] == node)
			return bt[(i + 1) / 2 - 1];
	return Nil;
}

// 二叉树bt存在,e是bt中的某个结点
// 返回e的左孩子,若无则返回Nil
int LeftChild(SqBiTree bt, int node)
{
	if (bt[0] == Nil)
		return Nil;
	for (int i = 0; i <= MAX_TREE_SIZE - 1; i++)
		if (bt[i] == node)
			return bt[(i + 1) * 2 - 1];
	return Nil;
}

// 二叉树bt存在,e是bt中的某个结点
// 返回e的右孩子,若无则返回Nil
int RightChild(SqBiTree bt, int e)
{
	if (bt[0] == Nil)
		return Nil;
	for (int i = 0; i <= MAX_TREE_SIZE - 1; i++)
		if (bt[i] == e)
			return bt[(i + 1) * 2];
	return Nil;
}

// 二叉树bt存在,e是bt中的某个结点
// 返回e的左兄弟,若无则返回Nil
int LeftSibling(SqBiTree bt, int e)
{
	if (bt[0] == Nil)
		return Nil;
	for (int i = 1; i <= MAX_TREE_SIZE; i++)
		// i是偶数,那么i-1是奇数,说明i是右孩子
		if (bt[i] == e && !(i % 2))
			return bt[i - 1];
	return Nil;
}

// 二叉树bt存在,e是bt中的某个结点
// 返回e的右兄弟,若无则返回Nil
int RightSibling(SqBiTree bt, int e)
{
	if (bt[0] == Nil)
		return Nil;
	for (int i = 1; i <= MAX_TREE_SIZE - 1; i++)
		// i是奇数,那么i+1是偶数,说明i是左孩子
		if (bt[i] == e && i % 2)
			return bt[i + 1];
	return Nil;
}

// 供PreOrderTraverse调用
void PreTraverse(SqBiTree bt, int i)
{
	intVisit(bt[i]);
	if (bt[2 * (i + 1) - 1] != Nil)
		PreTraverse(bt, 2 * (i + 1) - 1);
	if (bt[2 * (i + 1)] != Nil)
		PreTraverse(bt, 2 * (i + 1));
	return;
}
// 前序遍历算法
void PreOrderTraverse(SqBiTree bt)
{
	if (!BiTreeEmpty(bt))
		PreTraverse(bt, 0);
	printf("\n");
	return;
}

// 供InOrderTraverse()调用
void InTraverse(SqBiTree bt, int i)
{
	if (bt[2 * (i + 1) - 1] != Nil)
		InTraverse(bt, 2 * (i + 1) - 1);
	intVisit(bt[i]);
	if (bt[2 * (i + 1)] != Nil)
		InTraverse(bt, 2 * (i + 1));
	return;
}
// 中序遍历算法
void InOrderTraverse(SqBiTree bt)
{
	if (!BiTreeEmpty(bt))
		InTraverse(bt, 0);
	printf("\n");
	return;
}

// 供PostOrderTraverse()调用
void PostTraverse(SqBiTree bt, int i)
{
	if (bt[2 * (i + 1) - 1] != Nil)
		PostTraverse(bt, 2 * (i + 1) - 1);
	if (bt[2 * (i + 1)] != Nil)
		PostTraverse(bt, 2 * (i + 1));
	intVisit(bt[i]);
	return;
}
// 后序遍历算法
void PostOrderTraverse(SqBiTree bt)
{
	if (!BiTreeEmpty(bt))
		PostTraverse(bt, 0);
	printf("\n");
	return;
}

// 层序遍历算法
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

// 逐层,按本层序号输出二叉树
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
		printf("**************二叉树的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  遍历（先/中/后）                             *\n");
		printf("* 3  求结点个数                                   *\n");
		printf("* 4  求树的深度                                   *\n");
		printf("* 5  查找双亲                                     *\n");
		printf("* 6  查找兄弟（左/右）                            *\n");
		printf("* 7  查找孩子（左/右）                            *\n");
		printf("* 8  应用                                         *\n");
		printf("* 9  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("---------创建--------\n");
			InitBiTree(bt);
			CreateBiTree(bt);
			printf("创建完毕！\n");
			getchar();
			break;
		case 2:
			printf("---------遍历（先/中/后）-------\n");
			printf("前序遍历算法：");
			PreOrderTraverse(bt);
			printf("\n中序遍历算法：");
			InOrderTraverse(bt);
			printf("\n后序遍历算法：");
			PostOrderTraverse(bt);
			printf("\n遍历完毕！\n");
			break;
		case 3:
			printf("---------求结点个数-------\n");
			num = BiTreeNodesNum(bt);
			printf("结点个数为%d\n", num);
			printf("求结点个数完毕！\n");
			break;
		case 4:
			printf("---------求树的深度-------\n");
			num = BiTreeDepth(bt);
			printf("树的深度为%d\n", num);
			printf("求树的深度完毕！\n");
			break;
		case 5:
			printf("---------查找双亲-------\n");
			printf("输入要查找的结点的值：");
			while (scanf("%d", &index) != 1)
			{
				printf("结点的值必须是整型！\n");
			}
			value = Parent(bt, index);
			printf("结点%d，其双亲的值为%d\n", index, value);
			printf("查找双亲完毕！\n");
			break;
		case 6:
			printf("---------查找兄弟（左/右）-------\n");
			printf("输入要查找的结点的值：");
			while (scanf("%d", &index) != 1)
			{
				printf("结点的值必须是整型！\n");
			}
			value = LeftSibling(bt, index);
			printf("结点%d，其左兄弟的值为%d\n", index, value);
			value = RightSibling(bt, index);
			printf("结点%d，其右兄弟的值为%d\n", index, value);
			printf("查找兄弟完毕！\n");
			break;
		case 7:
			printf("---------查找孩子（左/右）-------\n");
			printf("输入要查找的结点的值：");
			while (scanf("%d", &index) != 1)
			{
				printf("结点的值必须是整型！\n");
			}
			value = LeftChild(bt, index);
			printf("结点%d，其左孩子的值为%d\n", index, value);
			value = RightChild(bt, index);
			printf("结点%d，其右孩子的值为%d\n", index, value);
			printf("查找孩子完毕！\n");
			break;
		case 8:
			printf("---------应用-------\n");
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
		printf("****************图的基本操作及应用*****************\n");
		printf("* 1  创建（邻接矩阵/邻接表）                      *\n");
		printf("* 2  遍历（深度/广度）                            *\n");
		printf("* 3  定位                                         *\n");
		printf("* 4  找第一个邻接点                               *\n");
		printf("* 5  找下一个邻接点                               *\n");
		printf("* 6  插入（点/边）                                *\n");
		printf("* 7  删除（点/边）                                *\n");
		printf("* 8  应用                                         *\n");
		printf("* 9  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("---------创建（邻接矩阵/邻接表）-------");
			break;
		case 2:
			printf("---------遍历（深度/广度）-------");
			break;
		case 3:
			printf("---------定位-------");
			break;
		case 4:
			printf("---------找第一个邻接点-------");
			break;
		case 5:
			printf("---------找下一个邻接点-------");
			break;
		case 6:
			printf("---------插入（点/边）-------");
			break;
		case 7:
			printf("---------删除（点/边）-------");
			break;
		case 8:
			printf("---------应用-------");
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
		printf("请选择：");
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
