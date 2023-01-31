#include<stdio.h>
#include<math.h>
int fun(int n)
{
	int n1=sqrt(n);
	if(n==n1*n1) return 1;
	else return 0;
}

int main()
{
	int m,n,i=0,flag=0;
	scanf("%d,%d",&m,&n);
	for(i=m;i<=n;i++)
	{
		if(fun(i)==1) flag++;
	}
	printf("%d\n",flag);
	return 0;
} 
