/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
typedef struct numLink
{
	int no;
	struct numLink *next;
}NODE;

NODE *monenode( NODE *head, int m );

void SetLink( NODE *h, int n )
{
	NODE *p=NULL, *q=NULL;
	int i;
	for( i=0; i<n; i++)
	{
		p = (NODE *)malloc(sizeof(NODE));//申请空间 
		p->no = i+1;//赋值 
		p->next = NULL;
		if( h->next == NULL )//第一个节点的情况 
		{
			h->next = p;
			q = p;//将p接上 
		}
		else
		{
			q->next = p;//得到的节点及数据接上原来的p，即现在的q 
			q = q->next;
		}
	}
	return;
}

int main( )
{
	int n,m;
	NODE *head=NULL, *q=NULL;
	scanf("%d%d",&n,&m);
	head = (NODE *)malloc(sizeof(NODE));
	head->no = -1;
	head->next = NULL;

	SetLink( head, n );

	q = monenode( head, m );

	do
	{
		printf("%d ",q->next->no);
		q = q->next;
	}while( q->next != NULL ); 
	printf("\n");
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


NODE *monenode( NODE *head, int m )
{
	NODE *p=head;
	while(m--)
	{
		NODE *q=head->next;//固定一个节点,便于找到后面的链表 
		while(p->next !=NULL) p=p->next ;
		p->next =q;
		head->next=q->next ;
		q->next =NULL;
	} 
	return head;
}
