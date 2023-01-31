#include<stdio.h>
int summar(int n,int m)
{
	int sum=0;
	if(m==n) sum+=m;
	else 
	{
		sum+=n;
		sum+=summar(n+1,m);
	}
	return sum;
}

int main()
{
	int x,y,tmp;
	scanf("%d%d",&x,&y);
	tmp=summar(x,y);
	printf("The sum from %d to %d is %d.\n",x,y,tmp);
	return 0;
}
