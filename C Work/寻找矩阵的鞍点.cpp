#include"stdio.h"
#define N 100
int main()
{
	int m,n,a[N][N],b[N],c[N],i,j,k1,k2,max,min,flag=0;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++) 
		for(j=0;j<n;j++) 
			scanf("%d",&a[i][j]);
	for(i=0;i<m;i++) //�ҵ��е����ֵ 
	{	
		max=0;
		for(j=0;j<n;j++)
		{  
			if(a[i][j]>max) 
			{
				max=a[i][j];
				b[i]=j;
			}
		}
	}
	for(j=0;j<n;j++) //�ҵ��е���Сֵ 
	{
		min=1000;
		for(i=0;i<m;i++)
		{
			if(a[i][j]<min)
			{
				min=a[i][j];
				c[j]=i;
			}
		}
	}
	for(i=0;i<m;i++) 
		if(c[b[i]]==i) //�������ֵΪ�±��ֵ�����е���Сֵ 
		{ 
			k1=i;k2=b[i];
			printf("Point:a[%d][%d]==%d\n",k1,k2,a[k1][k2]);
			flag++;
		}
	if(flag==0) printf("No Point\n");
	return 0;
}
