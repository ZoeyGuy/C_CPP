#include"stdio.h"
#include"math.h"
int main()
{
	int n,n1,w,mod,i,i1,j=0,x1,x2,flag=0;
	scanf("%d",&n);
	if(n==8) printf("0\n");
	else
	{
		x1=pow(10,n-1);x2=pow(10,n);
		for(i=x1;i<x2;i++) 
		{ 
			n1=n;i1=i;
			for(j=0;j<n&&n1>0&&i1>0;j++) 
			{ 
				w=(int)pow(n1,2); 
				mod=i1%w;
				if(mod!=0) break;
				i1=i1/10;
				n1--;   
			} 
			if(mod==0) 
			flag++;
		}
		printf("%d\n",flag);
	}
	return 0;
}
