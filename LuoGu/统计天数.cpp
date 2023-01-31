#include"stdio.h"
#define N 100000//洛谷提交记得改为1000000 
int main()
{
	int a[N],b[N]={0},f[N],e[N],i,j=0,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);//a[i]用来存每天的温度 
	f[j]=0;//f[j]用来表示每个递增小区间的左端点 
	for(i=0;i<n-1;i++)
	{
		if(a[i]<a[i+1]) 
		continue;
		else 
		{
			e[j]=i;//e[j]用来表示每个递增小区间的右端点 
			f[j+1]=i+1;
		}
		b[j]=e[j]-f[j]+1;//b[j]用来表示每个递增小区间的长度 
		j++;
 	}
	int max=b[0];
	for(i=1;i<n;i++)
	{
		if(b[i]>max) max=b[i];
	}
	printf("%d",max);
	return 0;
}
