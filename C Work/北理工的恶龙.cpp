#include"stdio.h"
#define N 100
int main()
{
	int n1,m1,n[N],m[N],i=0,j=0,tmp,sum=0;
	scanf("%d%d",&n1,&m1);
	for(i=0;i<n1;i++) scanf("%d",&n[i]);
	for(i=0;i<m1;i++) scanf("%d",&m[i]);
	if(n1>m1||n1<1||m1>100) printf("bit is doomed!\n");//确定数字范围，相当于报错
	else
	{
		for(i=0;i<n1-1;i++)
			for(j=0;j<n1-1-i;j++)
				if(n[j]>n[j+1])
				{
					tmp=n[j];
					n[j]=n[j+1];
					n[j+1]=tmp;
				}
		for(i=0;i<m1-1;i++)
			for(j=0;j<m1-1-i;j++)
				if(m[j]>m[j+1])
				{
					tmp=m[j];
					m[j]=m[j+1];
					m[j+1]=tmp;
				}
		i=j=0;
		while(i<n1&&j<m1)
		{
			if(m[j]>=n[i]) 
			{
				sum+=m[j];
				i++;
				j++;
			}
			else
			{
				j++;
			}
		}
		if(i<n1) printf("bit is doomed!\n");
		else printf("%d\n",sum);
	}
	return 0;
}
