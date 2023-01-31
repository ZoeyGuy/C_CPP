#include"stdio.h"
int main()
{
	int n=0;
	double S=0,c=0,i=0,K=0;
	scanf("%lf",&K);
	for(i=1;S<=K;i++)
	{
		c=1/i;
		S=S+c;
	}
	n=i-1;
	printf("%d",n);
	return 0;
}
