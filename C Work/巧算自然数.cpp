#include<stdio.h>
int main()
{
	int n,flag=0;
	scanf("%d",&n);
	while(n>1)
	{
		flag++;
		printf("%d,",n);
		if(n%2==0) n=n/2;
		else n=3*n+1;
	}
	printf("1\n");
	printf("step=%d\n",flag+1);
}
