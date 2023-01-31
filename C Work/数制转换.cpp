#include <stdio.h>
#include <math.h>
#include <string.h>
main()
{
	int i,j,h,k,l,o,p,q,c,d,f=0;
	char a[40],b[40],max1,max2;
	scanf("%s%s",&a,&b);
	i=strlen(a);//确定两个数的位数 
	j=strlen(b);
	max1=a[0];//找出两个数中各位数中的最大值 
	for(l=1;l<i;l++)
	{
		if(a[l]>max1) max1=a[l];
	}
	max2=b[0];
	for(o=1;o<j;o++)
	{
		if(b[o]>max2) max2=b[o];
	}
	if(max1>64) max1=max1-55;//陷阱！！!----得到的是ASCII值，要转换成十进制 
	else max1=max1-48;
	if(max2>64) max2=max2-55;
	else max2=max2-48;
	for(k=max1+1;k<=36;k++)//解释：如果出现A，证明其至少是十一进制，故不需要考虑比十一小的进制 
	{
		for(l=0,p=0;l<i;l++)//求出第一个数的值，即p 
		{
			if(a[l]>64) c=(a[l]-55)*pow(k,i-l-1);
			else c=(a[l]-48)*pow(k,i-l-1);
			p=p+c;
		}
		for(h=max2+1;h<=36;h++)//对第二个数进行讨论 
		{
			for(o=0,q=0;o<j;o++)//求出第二个数的值，即q 
			{
				if(b[o]>64) d=(b[o]-55)*pow(h,j-o-1); 
				else d=(b[o]-48)*pow(h,j-o-1);
				q=q+d;
			}
			if(q==p) 
			{	
				printf("%s (base %d) = %s (base %d)\n",a,k,b,h);
				f++;goto end;
			}
		}
	}
	if(f==0) printf("%s is not equal to %s in any base 2..36\n",a,b);
	end:return 0;
}
