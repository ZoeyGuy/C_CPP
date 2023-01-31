#include"stdio.h"
#define N 100 
int main()
{
	int n,i,j,k,flag=0;
	int a[N];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) //a[i]是最大数 
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(a[i]==a[j]+a[k]&&j!=k) 
				{
					flag++;
					goto S;//注意题目要求的是数的个数，不是满足条件的组合数 ！！！ 
				}
			} 
		} 
		S:continue;
	} 
	printf("%d",flag);
	return 0;
} 
