#include"stdio.h"
#define N 100
int main()
{
	int a[N],b[N]={0},n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(a[j]<a[i]) b[i]++;
	for(i=0;i<n;i++) printf("%d ",b[i]);
	return 0;
}
