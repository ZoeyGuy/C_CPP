#include<stdio.h>
#include <math.h>
int main()
{
   int n,i,j,num,t,s=0,t1,z=0;
   scanf("%d",&n);
   t=pow(10,n-1);
   for (i=t;i<t*10;i++)//确定起始位置 
   {
	   t1=i;
	   s=0;
	   for (j=1;t1!=0;j++)
	   {   
		   num=t1%10;
		   s+=pow(num,n);
		   t1=t1/10;
	   }
	   if(s==i)
	   {
		   z=1;//使用标志变量 
		   printf("%d\n",i);
	   }
   }
   if(z==0)
	   printf("No output.\n");
	return 0;
}
