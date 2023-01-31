/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"
#include "stdlib.h"

struct node
{	int data;
	struct node * next;
} ;

typedef struct node NODE;
typedef struct node * PNODE;

void outlist( PNODE );
void  ins_list( PNODE h, int num ) ;
int main ( )
{   
	int num=1;
	PNODE head;

	head = (PNODE)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;

	while ( num!=0 )
	{
		scanf("%d", &num);
		if ( num!=0 ) ins_list( head, num);
	}

	outlist( head );
	return 0;
}

void outlist( PNODE head )
{	
	PNODE p;
	p = head->next;
	while ( p != NULL )
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

/* This is an example for list. Please programme your code like it.*/

void sort_list( PNODE h, int num ) //使链表按升序排列的函数 
{
    PNODE p = h, n;
	n = (PNODE)malloc(sizeof(NODE));//建立一个含有该数字的节点 
	n->data = num;
	n->next = NULL;
	while (p->next != NULL && p->next->data < n->data) p = p->next;//找到数字应该放置的位置 
	if (p->next != NULL && p->next->data == n->data)	return;//若出现两个数字相同，则不放到链表中-------保证数字不重复 
	if (p->next == NULL)  //最开始的情况-----链表为空，直接放入数据，不需要比较 
	{
		p->next = n;
		n->next = NULL;
	}
	else//插入节点的常规操作 
	{
		n->next = p->next;
		p->next = n;
	}
}



/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


void ins_list( PNODE h, int num )//按输入顺序排列建立链表的函数 
{
    PNODE p = h, n;
	n = (PNODE)malloc(sizeof(NODE));//建立一个含有该数字的节点 
	n->data = num;
	n->next = NULL;//我jio得很有必要-----链表最后的数据节点要指向NULL 
	if (p->next == NULL)  //最开始的情况-----链表为空，直接放入数据，不需要比较 
	{
		p->next = n;
		n->next = NULL;
	}
	else//插入节点的常规操作 
	{
		while (p->next != NULL) p = p->next;
		n->next = p->next;
		p->next = n;
	}
}

