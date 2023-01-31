/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int         data;
    struct node * next;
} NODE;


NODE * find( NODE * , int * );
void outputring( NODE * );
void change( int , int , NODE * );


void outputring( NODE * pring )
{
	NODE * p;
	p = pring;
	if ( p == NULL )
		printf("NULL");
	else
		do
		{	printf("%d", p->data);
			p = p->next;
		} while ( p != pring );
	printf("\n");
	return;
}


//void out(NODE* head)//输出一个循环链表的40位-----TEST 
//{
//	NODE *p=head->next;
//	int n=40;
//	while(n--)
//	{
//		printf("%d ",p->data);
//		p=p->next;
//	}
//	printf("\n\n\n");
//} 


int main()
{
	int n, m;
	NODE * head, * pring;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;

	change( n, m, head );
	
	pring = find( head, &n );
	
//	out(head);

	printf("ring=%d\n", n);
	outputring( pring );

	return 0;
}

/*Here is waiting for you.*/
void change ( int n, int m, NODE * head )//此函数基本思路:模拟手算除法 
{
	if(m==0) return; //以防万一 
	int Rem[10000]; //保存余数 
	int Str[10000];//保存各位小数 ------即得到的商 
	int Div1=n,Div2=m;
	Div1*=10;    //这里要注意只能乘10！！！！！！！！！！！！！！！！ 
	Rem[0]=Div1%Div2;
	Str[0]=Div1/Div2;
	NODE *p,*pp,*q;
	p = (NODE*)malloc(sizeof(NODE));//p是个移动指针，始终在最后------方便最后是指回来还是指向NULL 
	p->data=Str[0];
	head->next=p;
//	p->next=NULL;
	int i=0;
	while(Rem[i++]!=0)
	{
		Div1=Rem[i-1]*10;//被除数变成上一次的余数*10；除数不变。 
		Rem[i]=Div1%Div2;
		Str[i]=Div1/Div2;
		int j=0;
		for(j=0;j<i;j++)//判断余数和商的组合之前有没有出现过-----找到循环节 
		{
			if(Rem[j]==Rem[i]&&Str[i]==Str[j])//一定要商和余数都相等才算循环 
			{
				q=head->next; 
				while(j--) //找到相等的点 
				{
					q=q->next;
				}
				p->next=q;//成环 
				return;
			}
		}
		if(j==i)//没找到之前相同的组合，就之间加在后面 
		{
			pp = (NODE*)malloc(sizeof(NODE));//要多次申请空间，因为有多个数要存储在不同的空间里 
			pp->data=Str[i];
//			pp->next=NULL;
			p->next=pp;
			p=pp;//固定p在最后 
		}
	}
	p->next=NULL;//非循环小数，指到NULL结束 
	return ;
}

NODE * find( NODE *head, int * n )
{
	NODE *pi=head,*qi=head; //pi为慢指针, qi为快指针; 
	while(qi!=NULL&&qi->next!=NULL) //若有NULL，一定是qi或者qi->next先达到 
	{
		pi=pi->next;
		qi=qi->next->next;
		if(pi==qi) break;
	}
	if(qi==NULL||qi->next==NULL)
	{
		*n=0;
		if(qi==NULL) return qi;                   //一定要分开写-----目的是返回一个空指针 
		else if(qi->next==NULL) return qi->next;
	}
	pi=head;//一个指针移到开头，二者共速运动 
	while(pi!=qi)
	{
		pi=pi->next;
		qi=qi->next;
	}
	int flag=1;//计算循环节的长度 
	qi=qi->next;
	while(pi!=qi)
	{
		qi=qi->next;
		flag++;
	}
	*n=flag;
	return pi;
}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
