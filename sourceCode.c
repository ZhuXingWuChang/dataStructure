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
			printf("两栈共享存储空间\n");
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
			printf("Double栈的长度为：%d。\n", DoubleStackLength(doubleStack));
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
			printf("---------应用-------\n");
			printf("队列的应用部分，见图的Breach First Seedgeh算法。\n");
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
	// 用一个for循环找到Tree中最后一个结点的为止
	for (lastNode = MAX_TREE_SIZE - 1; lastNode >= 0; lastNode--)
		if (bt[lastNode] != Nil)
			break;
	// 因为数组是以0开始,所以为了与定义的以1开始一致,这里加一
	lastNode++;
	// 用一个while循环计算Tree的深度
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

typedef enum
{
	Link,  // 0值代表Link,作为链使用
	Thread // 1值代表Thread,作为线索使用
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

// 按前序遍历算法的顺序来构造一棵树
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

// 全局变量,用来指向上一个访问过的结点(保存前驱结点的位置)
BiThrTree prevP = NULL;
// 用中序遍历进行中序线索化
void InThreading(BiThrTree currentP)
{
	if (currentP)
	{
		// 在中序遍历中,按照左根右的顺序,找到最左的子树
		InThreading(currentP->lchild);
		// 从最左边的子树开始往回递归,下面是递归过程中对当前左子树根节点的操作
		// 操作该结点,让其线索指到前驱
		if (!currentP->lchild)
		{
			currentP->LTag = Thread;
			currentP->lchild = prevP;
		}
		// 操作该结点的前驱结点,让其线索指到后继
		if (!prevP->rchild)
		{
			prevP->RTag = Thread;
			prevP->rchild = currentP;
		}
		// 该结点操作完毕,现在该结点称为前驱结点,递归
		prevP = currentP;
		// 操作完该子树的根结点,开始递归进入该子树的右子树
		InThreading(currentP->rchild);
	}
	return;
}
// 中序遍历二叉树,thrHead指向头结点,btt是二叉树本身
void InOrderThreading(BiThrTree* thrHead, BiThrTree btt)
{
	*thrHead = (BiThrTree)malloc(sizeof(BiThrNode));
	if (!*thrHead)
		exit(0);
	// 初始化头结点的lchild,它最终要作为Link,指向树的Root
	(*thrHead)->LTag = Link;
	(*thrHead)->lchild = NULL;
	// 初始化头结点的rchild,它最终要作为线索,指向中序遍历中的最后一个元素
	(*thrHead)->RTag = Thread;
	(*thrHead)->rchild = NULL;
	// 如果btt不是空树
	if (btt)
	{
		(*thrHead)->lchild = btt;
		// 在中序化线索前,以头结点为前一个结点,将其传入InThreading()中
		prevP = (*thrHead);
		InThreading(btt);
		// 在中序线索化后,全局变量prevP就成了最后一个结点
		prevP->RTag = Thread;
		// 最后一个结点的rchild指向头结点
		prevP->rchild = (*thrHead);
		// 头结点的rchild指向最后一个结点
		(*thrHead)->rchild = prevP;
	}
	return;
}

// 以非递归的形式(降低时间复杂度,这也是线索二叉树的目的所在)
// 来遍历整个二叉树btt
void InOrderTraverse_Thr(BiThrTree btt)
{
	BiThrTree currentP;
	currentP = btt->lchild;
	// 从根节点开始,遍历结束后会回到头结点(和循环链表一样)
	// 故以头结点作为判断循环是否结束的依据
	while (currentP != btt)
	{
		// 先找到最左的子树
		while (currentP->LTag == Link)
			currentP = currentP->lchild;
		// 循环结束后,currentP指向了最左子树的根结点
		charVisit(currentP->data);
		// 看最左子树是否有最右子树,如果没有,使用线索回到它的双亲
		while (currentP->RTag == Thread && currentP->rchild != btt)
		{
			currentP = currentP->rchild;
			charVisit(currentP->data);
		}
		// 剩下最后一种情况就是还剩Link右子树,那么进入
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
			BiThrTree mybtt, header;
			mybtt = InitBiThrTree(&mybtt);
			printf("按先序遍历法则创建一颗二叉树：\n");
			CreateBiThrTree(&mybtt);
			printf("创建完毕。线索化并中序遍历输出：\n");
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

// Vertex使用数组结构
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
	int i, j;       // i和j代表顶点的下标
	int weight;     // 边的权值
	EdgeNode* edge; // 存放新分配的结点, 插到链表中
	printf("输入顶点个数和边的个数：\n");
	scanf("%d%d", &graph->numVexs, &graph->numEdges);
	// 给AdjList[]中的各个VertexNode的data域赋初值, 并初始化firstedge域为NULL
	for (int k = 0; k < graph->numVexs; k++)
	{
		fflush(stdin);
		getchar();
		printf("给第%d个顶点赋值：\n", k + 1);
		scanf("%c", &graph->adjList[k].data);
		graph->adjList[k].firstedge = NULL;
	}
	// 给numEdges条边指定依附的结点, 并赋权值
	for (int k = 0; k < graph->numEdges; k++)
	{
		fflush(stdin);
		printf("输入第%d条边所连接的两个顶点，以及边的权值：\n", k + 1);
		scanf("%d%d%d", &i, &j, &weight);
		// 使用头插法将EdgeNode链到VertexNode上
		edge = (EdgeNode*)malloc(sizeof(EdgeNode));
		edge->adjvex = j - 1;
		edge->weight = weight;
		edge->next = graph->adjList[i - 1].firstedge;
		graph->adjList[i - 1].firstedge = edge;
		// 因为是无向图,所以adjList[i]和adjList[j]应该互指
		edge = (EdgeNode*)malloc(sizeof(EdgeNode));
		edge->adjvex = i - 1;
		edge->weight = weight;
		edge->next = graph->adjList[j - 1].firstedge;
		graph->adjList[j - 1].firstedge = edge;
	}
	return *graph;
}

// 标志访问的数组,用来标记该顶点是否已经被访问过
bool visited[MAXVEX];

// 深度优先遍历的操作,供下面的深度优先遍历函数调用
void DFS(ALGraph graph, int i)
{
	// 先设置访问标志为true
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
// 深度优先遍历,需要调用上面的DFS封装好的操作
void DFSTraverse(ALGraph graph)
{
	int i; // 访问顶点的下标变量
	// 先设置visited数组的标志为false
	for (i = 0; i < graph.numVexs; i++)
		visited[i] = false;
	for (i = 0; i < graph.numVexs; i++)
		if (!visited[i])
			DFS(graph, i);
	return;
}

void BFSTraverse(ALGraph graph)
{
	int i = 0;      // 访问顶点的下标变量
	EdgeNode* edge; // edge指针,在广度有限遍历的实现中使用
	LinkQueue queue;    // 广度优先队列
	queue = InitQueue(&queue);
	for (i = 0; i < graph.numVexs; i++)
		visited[i] = false;
	// 遍历每个顶点,并且进行广度优先遍历
	for (i = 0; i < graph.numVexs; i++)
	{
		if (!visited[i])
		{
			// 顶点的访问操作
			visited[i] = true;
			visit(graph.adjList[i].data);
			EnQueue(&queue, i);
			// 广度优先遍历的具体操作
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
*	graph: 需要插入顶点的图
*	value: 插入的新顶点的值
*	idnex: 新顶点需要与一个原顶点连接，index代表被连接顶点的下标
*	weight: 这条边的权值
*/
void InsertVex(ALGraph* graph, char value, int index, int weight)
{
	int num = 1;	// 计数变量，记下增加的边的个数
	EdgeNode* insertEdge;

	// 插入顶点操作
	graph->adjList[graph->numVexs].data = value;
	graph->adjList[graph->numVexs].firstedge = NULL;

	// 插入边操作
	if (index < graph->numVexs)
	{
		fflush(stdin);
		getchar();
		// 使用头插法将EdgeNode链到VertexNode上
		insertEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
		insertEdge->adjvex = index - 1;
		insertEdge->weight = weight;
		insertEdge->next = graph->adjList[graph->numVexs].firstedge;
		graph->adjList[graph->numVexs].firstedge = insertEdge;
		// 无向图，边有两个方向
		insertEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
		insertEdge->adjvex = graph->numVexs;
		insertEdge->weight = weight;
		insertEdge->next = graph->adjList[index - 1].firstedge;
		graph->adjList[graph->numVexs].firstedge = insertEdge;
	}

	graph->numVexs++;
	return;
}

// 邻接矩阵的数据结构,使用邻接矩阵更方便实现最小生成树算法
typedef struct
{
	char vexs[MAXVEX];
	int edge[MAXVEX][MAXVEX];
	int numVexs, numEdges;
} AMGraph;

AMGraph CreateAMGraph(AMGraph* graph)
{
	int i, j;   // i和j代表顶点的下标
	int weight; // 边的权值
	printf("输入顶点个数和边的个数：\n");
	scanf("%d%d", &graph->numVexs, &graph->numEdges);
	// 给各个顶点赋值
	for (int k = 0; k < graph->numVexs; k++)
	{
		printf("给第%d个顶点赋值：\n", k + 1);
		fflush(stdin);
		getchar();
		scanf("%c", &graph->vexs[k]);
	}
	// 给所有边默认赋值为INF(无权值)
	for (int i = 0; i < graph->numVexs; i++)
		for (int j = 0; j < graph->numVexs; j++)
			graph->edge[i][j] = INF;
	// 指定numEdges条边依附的顶点,以及权值
	for (int k = 0; k < graph->numEdges; k++)
	{
		printf("输入第%d条边所连接的两个顶点，以及边的权值：\n", k + 1);
		fflush(stdin);
		scanf("%d%d%d", &i, &j, &weight);
		graph->edge[i - 1][j - 1] = weight;
		graph->edge[j - 1][i - 1] = graph->edge[i - 1][j - 1];
	}
	return *graph;
}

// 手动输入一个图的过程过于复杂，故封装一个默认的邻接矩阵生成过程于该函数中
void _CreateAMGraph(AMGraph* G)
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
	G->numEdges = 15;
	G->numVexs = 9;

	for (i = 0; i < G->numVexs; i++)/* 初始化图 */
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

// Prim算法生成最小生成树(Minumum Cost Spanning Tree)
void MiniSpanTree_Prim(AMGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		/* 保存相关顶点下标 */
	int lowcost[MAXVEX];	/* 保存相关顶点间边的权值 */
	lowcost[0] = 0;/* 初始化第一个权值为0，即v0加入生成树 */
			/* lowcost的值为0，在这里就是此下标的顶点已经加入生成树 */
	adjvex[0] = 0;			/* 初始化第一个顶点下标为0 */
	for (i = 1; i < G.numVexs; i++)	/* 循环除下标为0外的全部顶点 */
	{
		lowcost[i] = G.edge[0][i];	/* 将v0顶点与之有边的权值存入数组 */
		adjvex[i] = 0;					/* 初始化都为v0的下标 */
	}
	for (i = 1; i < G.numVexs; i++)
	{
		min = INF;	/* 初始化最小权值为∞， */
						/* 通常设置为不可能的大数字如32767、65535等 */
		j = 1; k = 0;
		while (j < G.numVexs)	/* 循环全部顶点 */
		{
			if (lowcost[j] != 0 && lowcost[j] < min)/* 如果权值不为0且权值小于min */
			{
				min = lowcost[j];	/* 则让当前权值成为最小值 */
				k = j;			/* 将当前最小值的下标存入k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);/* 打印当前顶点边中权值最小的边 */
		lowcost[k] = 0;/* 将当前顶点的权值设置为0,表示此顶点已经完成任务 */
		for (j = 1; j < G.numVexs; j++)	/* 循环所有顶点 */
		{
			if (lowcost[j] != 0 && G.edge[k][j] < lowcost[j])
			{/* 如果下标为k顶点各边权值小于此前这些顶点未被加入生成树权值 */
				lowcost[j] = G.edge[k][j];/* 将较小的权值存入lowcost相应位置 */
				adjvex[j] = k;				/* 将下标为k的顶点存入adjvex */
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
			printf("---------创建（邻接矩阵/邻接表）-------\n");
			graph = CreateALGraph(&graph);
			printf("创建邻接表完毕！\n");
			break;
		case 2:
			printf("---------遍历（深度/广度）-------\n");
			printf("深度优先遍历：\n");
			DFSTraverse(graph);
			printf("\n广度优先遍历：\n");
			BFSTraverse(graph);
			printf("\n遍历结束！\n");
			break;
		case 3:
			printf("---------定位-------\n");
			printf("请输入顶点的值：\n");
			getchar();
			while (scanf("%c", &vexValue) != 1)
			{
				fflush(stdin);
				getchar();
				printf("请输入字符型值！\n");
			}
			index = FindValue(graph, vexValue);
			printf("定位结果为%d（0代表找不到该顶点）。\n", index);
			printf("定位结束！\n");
			break;
		case 4:
			printf("---------找第一个邻接点-------\n");
			vexValue = FindFirstVex(graph);
			printf("第一个邻接点的值为%c。\n", vexValue);
			printf("查找完毕！\n");
			break;
		case 5:
			printf("---------找下一个邻接点-------\n");
			printf("输入值，查找该值对应顶点的下一个邻接点：\n");
			getchar();
			while (scanf("%c", &vexValue) != 1)
			{
				fflush(stdin);
				getchar();
				printf("请输入字符型值！\n");
			}
			vexValue = FindNextVex(graph, vexValue);
			printf("下一个邻接点的值为%c。\n", vexValue);
			printf("查找完毕！\n");
			break;
		case 6:
			printf("---------插入（点/边）-------\n");
			printf("请输入插入的顶点的值：\n");
			getchar();
			while (scanf("%c", &vexValue) != 1)
			{
				fflush(stdin);
				printf("请输入字符型值！\n");
			}
			printf("请输入与其连接的顶点的下标和权值（#代表退出）：\n");
			getchar();
			scanf("%d%d", &index, &weight);
			InsertVex(&graph, vexValue, index, weight);
			printf("插入点完毕！\n");
			break;
		case 7:
			printf("---------删除（点/边）-------\n");
			printf("输入删除的顶点的下标：\n");
			while (scanf("%d", &index) != 1 && index > graph.numVexs)
			{
				printf("重新输入！\n");
			}
			graph.adjList[index - 1].data = -INF;
			printf("删除点完毕！\n");
			break;
		case 8:
			printf("---------应用-------\n");
			printf("使用邻接矩阵实现最小生成树算法\n");
			_CreateAMGraph(&matrix);
			MiniSpanTree_Prim(matrix);
			printf("实现完毕！\n");
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
