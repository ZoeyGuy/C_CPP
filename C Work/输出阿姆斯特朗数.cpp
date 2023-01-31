//一定一定一定要清零！！！！ 
#include"stdio.h"
#include"math.h"
#include"stdlib.h"
int main()
{	int x=0,n,y=0,a[6]={0},b[6]={0},c[6]={0},d[6]={0},flag=0,sum=0;
	scanf("%d",&n);
	y=(int)pow(10,(double)n-1);
	for(x=y;x<y*10;x++)
	{
		sum=0;
		for(int i=0;i<6;i++)
		{	
			c[i]=(int)pow(10.0,(double)i);
			a[i]=x/c[i];
			d[i]=a[i]%10;
			if(d[i]!=0) {b[i]=(int)pow((double)d[i],(double)n);sum+=b[i];}
		}
		if(x==sum)
		{
			flag=1;
			printf("%d\n",x);
		}
	}
	if(flag==0)	printf("No output.\n");
}
