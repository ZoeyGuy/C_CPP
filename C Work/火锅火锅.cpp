#include"stdio.h"
#define N 10000   //��Ķ���Ҫ������ȷ 
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
		for(j=0;j<n;j++)   //ע�⻹����ȡ�м�һ�����������֣��������Ҫ�仯������ 
		{
			for(k=j;k<n;k++)
			{
				sum+=s[k];
				if(max<sum) max=sum;
			}
			sum=0;    //һ��һ��Ҫ���㣡������������
		}
		printf("%d\n",max);
	}
	return 0;
}
