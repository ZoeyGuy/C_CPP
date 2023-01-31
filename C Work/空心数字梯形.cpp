#include"stdio.h"

int main()
{	
	int row=0,first=0,first2=0,i=0,j=0,a,b,c,d,e,f,g;
	scanf("%d%d",&row,&first);
	first2=first;
	for(i=0;i<row-1+(row+1)/2;i++)  //输出第一行
	{                    
		a=first2%10;
		first2++;
		printf("%-2d",a);
	}
	if(row%2==0) b=a+30;
	else b=a+29;
	for(i=row+(row+1)/2;i<=3*row-2;i++)
	{
		c=b%10;
		printf("%-2d",c);
		b--;
	}
	printf("\n");
	for(i=2;i<=row-1;i++)  //输出中间行
	{
		for(j=1;j<=3*row-i-1;j++)
		{
			if(j==i||j==3*row-i-1) printf("%-2d",(i-1+first)%10);
			else printf("  ");
		}
		printf("\n");
	}
	for(i=1;i<=row-1;i++) {printf("  ");}  //输出最后一行 
	d=first+row-1;
	for(i=row;i<=row-1+(row+1)/2;i++)
	{
		e=d%10;
		printf("%-2d",e);d++;
	}
	if(row%2==0) f=e+10;
	else f=e+9;
	for(i=row+(row+1)/2;i<=2*row-1;i++)
	{
		g=f%10;
		printf("%-2d",g);
		f--;
	}
	printf("\n");
	return 0;
}
