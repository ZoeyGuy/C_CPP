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


//void out(NODE* head)//���һ��ѭ�������40λ-----TEST 
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
void change ( int n, int m, NODE * head )//�˺�������˼·:ģ��������� 
{
	if(m==0) return; //�Է���һ 
	int Rem[10000]; //�������� 
	int Str[10000];//�����λС�� ------���õ����� 
	int Div1=n,Div2=m;
	Div1*=10;    //����Ҫע��ֻ�ܳ�10�������������������������������� 
	Rem[0]=Div1%Div2;
	Str[0]=Div1/Div2;
	NODE *p,*pp,*q;
	p = (NODE*)malloc(sizeof(NODE));//p�Ǹ��ƶ�ָ�룬ʼ�������------���������ָ��������ָ��NULL 
	p->data=Str[0];
	head->next=p;
//	p->next=NULL;
	int i=0;
	while(Rem[i++]!=0)
	{
		Div1=Rem[i-1]*10;//�����������һ�ε�����*10���������䡣 
		Rem[i]=Div1%Div2;
		Str[i]=Div1/Div2;
		int j=0;
		for(j=0;j<i;j++)//�ж��������̵����֮ǰ��û�г��ֹ�-----�ҵ�ѭ���� 
		{
			if(Rem[j]==Rem[i]&&Str[i]==Str[j])//һ��Ҫ�̺���������Ȳ���ѭ�� 
			{
				q=head->next; 
				while(j--) //�ҵ���ȵĵ� 
				{
					q=q->next;
				}
				p->next=q;//�ɻ� 
				return;
			}
		}
		if(j==i)//û�ҵ�֮ǰ��ͬ����ϣ���֮����ں��� 
		{
			pp = (NODE*)malloc(sizeof(NODE));//Ҫ�������ռ䣬��Ϊ�ж����Ҫ�洢�ڲ�ͬ�Ŀռ��� 
			pp->data=Str[i];
//			pp->next=NULL;
			p->next=pp;
			p=pp;//�̶�p����� 
		}
	}
	p->next=NULL;//��ѭ��С����ָ��NULL���� 
	return ;
}

NODE * find( NODE *head, int * n )
{
	NODE *pi=head,*qi=head; //piΪ��ָ��, qiΪ��ָ��; 
	while(qi!=NULL&&qi->next!=NULL) //����NULL��һ����qi����qi->next�ȴﵽ 
	{
		pi=pi->next;
		qi=qi->next->next;
		if(pi==qi) break;
	}
	if(qi==NULL||qi->next==NULL)
	{
		*n=0;
		if(qi==NULL) return qi;                   //һ��Ҫ�ֿ�д-----Ŀ���Ƿ���һ����ָ�� 
		else if(qi->next==NULL) return qi->next;
	}
	pi=head;//һ��ָ���Ƶ���ͷ�����߹����˶� 
	while(pi!=qi)
	{
		pi=pi->next;
		qi=qi->next;
	}
	int flag=1;//����ѭ���ڵĳ��� 
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
