#include<stdio.h>
#include<math.h>
int main()
{
	int num=0;
	scanf("%d",&num);
	float n1;
	n1=0.5*(sqrt(1+8.0*num)-1);
	int n;
	n=(int)n1;
	int x,y,dec;
	dec=num-(n*n+n)/2;
	if(n%2==0)
	{
		y=dec;
		x=n+1-y+1;
		if(y==0) //�����ڱ߽��ϵ���� 
		{
			y++;
			x-=2;
		}
	}
	else
	{
		y=n+1-dec+1;
		x=dec;
		if(x==0)//�����ڱ߽��ϵ���� 
		{
			x++;
			y-=2; 
		}
	}
	printf("%d/%d",x,y);
	return 0;
} 
