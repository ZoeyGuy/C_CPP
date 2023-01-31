#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

int compare(int a,int b)
{
	int flag;
	switch(a)
	{
		case 0: if(b==1||b==4) flag=-1;
				else if(b==0) flag=0;
				else flag=1;break;
		case 1: if(b==2||b==4) flag=-1;
				else if(b==1) flag=0;
				else flag=1;break;
		case 2: if(b==0||b==3) flag=-1;
				else if(b==2) flag=0;
				else flag=1;break;
		case 3: if(b==0||b==1) flag=-1;
				else if(b==3) flag=0;
				else flag=1;break;
		case 4: if(b==2||b==3) flag=-1;
				else if(b==4) flag=0;
				else flag=1;break;
	}
	return flag;
}

void CreatList(NODE* head, int n)
{
	NODE *p,*q=head;
	int num;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		p=(NODE*)malloc(sizeof(NODE));
		p->data=num;
		q->next=p;
		q=p;
	}
	q->next=head->next;
}

int main()
{
	int N,NA,NB;
	scanf("%d%d%d",&N,&NA,&NB);
	NODE *head_a, *head_b;
	head_a=(NODE*)malloc(sizeof(NODE));
	head_b=(NODE*)malloc(sizeof(NODE));
	head_a->data=-1;
	head_b->data=-1;
	head_a->next=NULL;
	head_b->next=NULL;
	CreatList(head_a,NA);
	CreatList(head_b,NB);
	int mark_a=0,mark_b=0;
	NODE *pp=head_a->next, *qq=head_b->next;
	for(int i=0;i<N;i++)
	{
		if(compare(pp->data,qq->data)>0) mark_a++;
		else if(compare(pp->data,qq->data)<0) mark_b++;
		pp=pp->next;
		qq=qq->next;
	}
	printf("%d %d",mark_a,mark_b);
	return 0;
}
