#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
typedef struct node
{
	char cha;
	struct node *next;
}NODE;

void setlink(NODE *head)
{
	NODE *p=NULL;
	char cc;
	while(1)
	{
		cc=getchar();
		if(cc=='\n') return;
		p=(NODE*)malloc(sizeof(NODE));
		p->cha =cc;
		p->next =NULL;
		if(cc>' ')
		{
			if(head->next == NULL) head->next = p;
			else
			{
				NODE *q=head;
				while(q->next !=NULL) q=q->next ;
				q->next = p;
//				p->next = NULL;
			}
		}
	}
}

void insert(NODE*head)
{
	char dd;
	
	while(1)
	{
		NODE *p,*q=NULL;
		p=head;//初始化呀!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
		dd=getchar();
		if(dd=='\n') return;
		if(dd>' ')
		{
			q=(NODE*)malloc(sizeof(NODE));
			q->cha =dd;
			q->next =NULL;
			while(p->next !=NULL&&q->cha > p->next->cha )
			p=p->next ;
			if(p->next !=NULL&&p->next->cha == q->cha )//一定要注意不要访问NULL的数据域 
			continue;
			if(p->next == NULL)
			{
				p->next = q;
				q->next = NULL;
			}
			else
			{
				q->next = p->next ;
				p->next =q;
			}
		}
	}
}

void outlink(NODE *head)
{
	NODE *p=head;
	while(p->next->next  !=NULL)
	{
		printf("%c ",p->next->cha );
		p=p->next ;
	}
	printf("%c\n",p->next->cha );
}

int main()
{
	NODE *head;
	head=(NODE*)malloc(sizeof(NODE));
	head->cha ='\0';
	head->next =NULL;
	setlink(head);
	insert(head);
	outlink(head);
	return 0;
}
