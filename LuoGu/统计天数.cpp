#include"stdio.h"
#define N 100000//����ύ�ǵø�Ϊ1000000 
int main()
{
	int a[N],b[N]={0},f[N],e[N],i,j=0,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);//a[i]������ÿ����¶� 
	f[j]=0;//f[j]������ʾÿ������С�������˵� 
	for(i=0;i<n-1;i++)
	{
		if(a[i]<a[i+1]) 
		continue;
		else 
		{
			e[j]=i;//e[j]������ʾÿ������С������Ҷ˵� 
			f[j+1]=i+1;
		}
		b[j]=e[j]-f[j]+1;//b[j]������ʾÿ������С����ĳ��� 
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
