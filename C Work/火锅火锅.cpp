#include"stdio.h"
#define N 10000   //宏的定义要尽量精确 
int main()
{
	int T,n,i,j,k,s[N],t[N],sum=0,max;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++) 
		{
			scanf("%d",&s[j]);
		}
		max=-1000;
		for(j=0;j<n;j++)   //注意还可以取中间一段连续的数字，所以起点要变化！！！ 
		{
			for(k=j;k<n;k++)
			{
				sum+=s[k];
				if(max<sum) max=sum;
			}
			sum=0;    //一定一定要清零！！！！！！！
		}
		printf("%d\n",max);
	}
	return 0;
}
