#include"stdio.h"
int main()
{
	int a[11],i,j=0;
	for(i=0;i<11;i++) scanf("%d",&a[i]);
	for(i=0;i<10;i++)
		if(a[i]<=a[10]+30) j++;
	printf("%d",j);
	return 0;
}
