#include"stdio.h"
int main()
{
	int i,j;
	double x,s=0,a;
	scanf("%lf",&x);
	a=2.0;
	for(i=1;s<x;i++)
	{
		s+=a;
		a*=0.98; 
	}
	j=i-1;
	printf("%d",j);
	return 0;
}
