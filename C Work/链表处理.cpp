/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct sdata
{  
	int num;
	struct sdata *next;
} SNODE;

void movenode( SNODE *, int );//说明有时先声明函数时可以不加参数 

void setlink( SNODE * head, int n )
{   
	SNODE *p;

	while ( n > 0 )
	{   
		p = ( SNODE * ) malloc( sizeof( SNODE ) );
		p->num = n;
		p->next = head->next;
		head->next = p;
		n --;
	}
}

void outlink( SNODE * head )
{
	while( head->next != NULL )
	{
		head = head->next;
		printf( "%d,", head->num );
    }
	return;//不是只有含返回值的函数才能用return ---------remember！！！ 
}

int main( )
{   
	int n, m;
	SNODE * head = NULL;

	scanf("%d%d", &n, &m );//n为链表长度 ，也是链表数据域的值 
	head = ( SNODE * ) malloc( sizeof( SNODE ) );
	head->num = -1;
	head->next = NULL;
	setlink( head, n );

	movenode( head, m );   /* This is waiting for you. */

	outlink( head );
    printf("\n");
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void movenode( SNODE *head, int n)
{
	SNODE *p=head,*pp;
	while(p->next !=NULL&&p->next->num!=n) p=p->next;//一定要加前面的那个条件------访问NULL的数据域是非法的 
	if(p->next !=NULL)
	{
		pp=p->next ;
		p->next =pp->next ;
		pp->next =head->next ;
		head->next =pp;
	}
	else return;
}
