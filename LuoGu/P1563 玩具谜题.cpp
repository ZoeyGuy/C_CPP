#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

#define MAX 10000 //��ȼӸ�0������˵ 
/*
typedef struct Dbnode
{
	struct Dbnode *last;
	char s[10];
	int flag;
	struct Dbnode *next;
}DB;

void Creat_Cicle_List(DB *head,int n)
{
	DB *p,*q=head;
	int z=0;//��־���� 
	for(int i=0;i<n;i++)
	{
		int flags;
		char str[10];
		scanf("%d%s",&flags,str);
		p=(DB*)malloc(sizeof(DB));
		p->flag=flags;
		strcpy(p->s,str);
		if(z!=0)
		{
			q->next=p;
			p->last=q;
			q=p;
		}
		else
		{
			q->next=p;
			q=p;
			z=1;
		}
	}
	q->next=head->next;//���ɻ� 
	head->next->last=q; 
}

DB *Find_Node(DB *p,int m)
{
	int flag1,num;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&flag1,&num);
		if(flag1^(p->flag))//�˴������������� 
		{
			while(num--)
			{
				p=p->next;
			}
		}
		else
		{
			while(num--)
			{
				p=p->last;
			}
		}
	}
	return p;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	DB *head=(DB*)malloc(sizeof(DB));
	head->last=NULL;
	head->next=NULL;
	Creat_Cicle_List(head,n);
	DB *pp=head->next;//��ʼ�Ľڵ�
	pp=Find_Node(pp,m);
	printf("%s",pp->s);
}

/***���ϴ���ʹ��˫����������Ȼʮ�ֵ���������������������***/ 

/***�������ʹ���������Ӳ�յ�����            ����������Ҳ��Ӳ�ա�����������***/

int main()
{
	int flag1[MAX],flag2[MAX],num[MAX];
	char str[MAX][12];
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%s",&flag1[i],str[i]);
	}
	int k=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&flag2[i],&num[i]);
		if(flag2[i]^flag1[k])
		{
			k=(k+num[i]+n)%n;//����һ��ģ����ֹ�������� 
		}
		else
		{
			k=(k-num[i]+n)%n;
		}
	}
	printf("%s",str[k]);
	return 0;
} 
