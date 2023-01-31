#include<stdio.h>
int main()
{
	int i=0,j=0,sum,a[7],fst=2;
	for(i=0;i<7;i++)
	{
		a[i]=fst+2;
		fst=(fst+1)*2;
	}
	sum=fst;
	printf("sum=%d\n",sum);
	for(i=6;i>=0;i--) printf("sell=%d,",a[i]);
	printf("\n");
	return 0;
}
