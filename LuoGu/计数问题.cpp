#include"stdio.h"
int main()
{
	int i=0,i1=0,i2=0,j=0,x,n;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)
	{
		i2=i;
		while(i2>0)
		{
			i1=i2%10;
			i2=i2/10;
			if(i1==x) j++;
		}
	}
	printf("%d",j);
	return 0;
}
