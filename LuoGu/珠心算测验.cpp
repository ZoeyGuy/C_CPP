#include"stdio.h"
#define N 100 
int main()
{
	int n,i,j,k,flag=0;
	int a[N];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) //a[i]������� 
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(a[i]==a[j]+a[k]&&j!=k) 
				{
					flag++;
					goto S;//ע����ĿҪ��������ĸ������������������������ ������ 
				}
			} 
		} 
		S:continue;
	} 
	printf("%d",flag);
	return 0;
} 
