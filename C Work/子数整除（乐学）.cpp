#include<stdio.h>
int main()
{
	int K,i=0,sub1,sub2,sub3;
	scanf("%d",&K);
	for(i=10000;i<=30000;i++)
	{
		sub1=i/100;
		sub2=(i/10)%1000;
		sub3=i%1000;
		if(sub1%K==0&&sub2%K==0&&sub3%K==0) printf("%d\n",i);
	}
	return 0;
} 
