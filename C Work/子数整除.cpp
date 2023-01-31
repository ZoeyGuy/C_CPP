#include"stdio.h"
int main()
{
	int K,i,j,sub1,sub2,sub3;
	scanf("%d",&K);
	for(i=1e4;i<=3e4;i++)
	{
		sub1=i/100;
		sub2=(i%10000)/10;
		sub3=i%1000;
		if(sub1%K==0&&sub2%K==0&&sub3%K==0) printf("%d\n",i);
	}
	return 0;
}
