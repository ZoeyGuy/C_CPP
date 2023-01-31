#include<stdio.h>
#define N 5000
int main()
{
	int n,s,a,b,x[N][2];
	scanf("%d%d%d%d",&n,&s,&a,&b);
	for(int i=0;i<n;i++) scanf("%d%d",&x[i][0],&x[i][1]);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(x[i][1]>x[j][1])
			{
				int tmp1=x[i][1];  int tmp2=x[i][0]; 
				x[i][1]=x[j][1];       x[i][0]=x[j][0];
				x[j][1]=tmp1;          x[j][0]=tmp2;
			}
		}
	}
	int flag=0;
	for(int i=0;i<n&&s>=0;i++)
	{
		if(x[i][0]<=a+b)
		{
			flag++;
			s=s-x[i][1];
		}
	}
	if(s<0) flag--;
	printf("%d",flag);
	return 0;
} 
