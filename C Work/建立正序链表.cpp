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

void sort_list( PNODE h, int num ) //ʹ�����������еĺ��� 
{
    PNODE p = h, n;
	n = (PNODE)malloc(sizeof(NODE));//����һ�����и����ֵĽڵ� 
	n->data = num;
	n->next = NULL;
	while (p->next != NULL && p->next->data < n->data) p = p->next;//�ҵ�����Ӧ�÷��õ�λ�� 
	if (p->next != NULL && p->next->data == n->data)	return;//����������������ͬ���򲻷ŵ�������-------��֤���ֲ��ظ� 
	if (p->next == NULL)  //�ʼ�����-----����Ϊ�գ�ֱ�ӷ������ݣ�����Ҫ�Ƚ� 
	{
		p->next = n;
		n->next = NULL;
	}
	else//����ڵ�ĳ������ 
	{
		n->next = p->next;
		p->next = n;
	}
}



/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


void ins_list( PNODE h, int num )//������˳�����н�������ĺ��� 
{
    PNODE p = h, n;
	n = (PNODE)malloc(sizeof(NODE));//����һ�����и����ֵĽڵ� 
	n->data = num;
	n->next = NULL;//��jio�ú��б�Ҫ-----�����������ݽڵ�Ҫָ��NULL 
	if (p->next == NULL)  //�ʼ�����-----����Ϊ�գ�ֱ�ӷ������ݣ�����Ҫ�Ƚ� 
	{
		p->next = n;
		n->next = NULL;
	}
	else//����ڵ�ĳ������ 
	{
		while (p->next != NULL) p = p->next;
		n->next = p->next;
		p->next = n;
	}
}

