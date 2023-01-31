#include"stdio.h"
int main()
{
	int a[7],p[3],n[3],i,min;     //n为数量，p为费用   
	for(i=0;i<7;i++)  scanf("%d",&a[i]);
	for(i=0;i<3;i++)
	{
		n[i]=a[0]/a[2*i+1];
		if(a[0]!=n[i]*a[2*i+1]) n[i]++;
		p[i]=a[2*i+2]*n[i];
	}
	min=p[0];
	for(i=0;i<3;i++)
	{
		if(min>p[i]) min=p[i];
	}
	printf("%d",min);
	return 0;
}
