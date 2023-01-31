#include"stdio.h"
int main()
{
	int a[12];
	int i,j,s=0,r=0,d=0,c=0,p=0,q=0;
	for(i=0;i<12;i++) scanf("%d",&a[i]);
	for(j=0;j<12;j++)
	{
		s+=(300-a[j]);  //s为预算多出来的钱 
		r=s%100;   //r为储蓄完之后剩余的钱 
		d=r+300;    //d为第二年手里的钱 
		if(d<a[j+1]) {printf("-%d",j+2);goto end;}
		p=s-r;  //p为每年存的钱 
		c+=p;  //c为总共储存的钱 
		s-=p;
	}
	q=(int)(r+1.2*c);
	printf("%d",q);
	end:return 0;
}
