#include <stdio.h>
#include <string.h>
#include <malloc.h>
//#include <conio.h>
#include <stdlib.h>
typedef int ElemType;
#define STACK_SIZE 10
#define STACK_INCRE 3
#define N 8
//定义栈的存储结构
struct Sqstack
{
	ElemType *base;
	ElemType *top;
	int stacksize;
};

//初始化栈 s
void InitStack(Sqstack &s)
{
	s.base = (ElemType *)malloc(STACK_SIZE * sizeof(ElemType));
	if (!s.base)
		exit(1);
	s.top = s.base;
	s.stacksize = STACK_SIZE;
	printf("栈 s 已被初始化:\n");
}

//向栈 s 的第 i 个位置压入元素 e
void Push(Sqstack &s, ElemType e, int i)
{
	// static int i=1;
	if (s.top - s.base == STACK_SIZE)
	{
		s.base = (ElemType *)realloc(s.base, (s.stacksize + STACK_INCRE) * sizeof(ElemType));
		s.top = s.base + s.stacksize;
		s.stacksize += STACK_INCRE;
	}
	*(s.top) = e;
	s.top++;
	printf("向栈中已经成功压入第%d 个元素:%d\n", i, e);
	// i++;
}

//对栈 s 中的每个元素一次调用 vi()函数
void StackTreaverse(Sqstack s, void (*vi)(ElemType))
{
	int i = 0;
	i = s.top - s.base;
	printf("遍历栈 s 中的%d 个元素\n", i);
	i = 0;
	while (s.top > s.base)
	{
		vi(*s.base++);
		i++;
	}
	printf("已经遍历栈中%d 元素:\n", i);
}

//在屏幕上打印该元素
void print(ElemType e)
{
	printf("%d\n", e);
}

//输出栈 s 的栈顶元素，并赋值给变量 e
int Pop(Sqstack &s, ElemType &e)
{
	if (s.top == s.base)
		return 0;
	--s.top;
	e = *s.top;
	return 1;
}

//判断栈 s 是否为空，如果是返回 1，否则返回 0
int StackEmpty(Sqstack s)
{
	if (s.base == s.top)
		return 1;
	else
		return 0;
}

//获取栈 s 的栈顶元素
int GetStackTop(Sqstack s, ElemType &e)
{
	if (s.base == s.top)
		return 0;
	else
	{
		s.top--;
		e = *(s.top);
		return 1;
	}
}

//获取栈 s 的长度
int StackLength(Sqstack s)
{
	return s.top - s.base;
}

//把栈 s 置为空栈
void ClearStack(Sqstack &s)
{
	printf("把栈置为空栈:\n");
	s.top = s.base;
}

//将栈 s 销毁
void DestroyStack(Sqstack &s)
{
	printf("销毁栈:\n");
	free(s.base);
	s.top = s.base = NULL;
	s.stacksize = 0;
}

int main()
{
	int flag, SLength, j, i = 1;
	scanf("%d", &flag);
	Sqstack s;
	ElemType e;
	InitStack(s);
	printf("\n");
	for (j = 0; j < s.stacksize; j++, i++)
		Push(s, j, i);
	printf("\n");
	StackTreaverse(s, print);
	printf("\n");
	flag = Pop(s, e);
	printf("如果 flag 等于 1 表示出栈成功，如果 flag 等于 0 表示出栈失败:flag=%d;栈顶元素为:%d\n", flag, e);
	printf("\n");
	flag = StackEmpty(s);
	printf("如果 flag 等于 1 表示 s 栈为空，如果 flag 等于 0 表示栈 s 非空:flag=%d:\n", flag);
	printf("\n");
	flag = GetStackTop(s, e);
	printf("如果 flag 等于 1 表示获取栈 s 栈顶元素成功，如果 flag 等于 0 表示获取栈 s 栈顶元素失败:flag=%d;栈顶元素为:%d\n", flag, e);
	printf("\n");
	SLength = StackLength(s);

	printf("此时栈 s 的长度为:%d\n", SLength);
	printf("\n");
	ClearStack(s);
	flag = StackEmpty(s);
	printf("如果 flag 等于 1 表示 s 栈为空，如果 flag 等于 0 表示栈 s 非空:flag=%d:\n", flag);
	printf("\n");
	DestroyStack(s);
	return 0;
}