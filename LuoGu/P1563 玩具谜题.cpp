#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

#define MAX 10000 //洛谷加个0，不多说 
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
	int z=0;//标志变量 
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
	q->next=head->next;//最后成环 
	head->next->last=q; 
}

DB *Find_Node(DB *p,int m)
{
	int flag1,num;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&flag1,&num);
		if(flag1^(p->flag))//此处异或运算很巧妙 
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
	DB *pp=head->next;//开始的节点
	pp=Find_Node(pp,m);
	printf("%s",pp->s);
}

/***以上代码使用双向链表，但显然十分的慢！！！！！！！！！***/ 

/***下面介绍使用数组进行硬刚的做法            （好像上面也是硬刚。。。。。）***/

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
			k=(k+num[i]+n)%n;//加上一个模，防止负数出现 
		}
		else
		{
			k=(k-num[i]+n)%n;
		}
	}
	printf("%s",str[k]);
	return 0;
} 
