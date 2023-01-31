//套公式，注意数据类型 
#include<stdio.h>
#include<math.h>
int main ()
{	int a,c;
	double d,p,q,x1,x2,b;
	scanf("%d%lf%d",&a,&b,&c);
	d=b*b-4*a*c; 
	if(a==0)
	{	
		if(b==0)
		{	
			printf("Input error!\n");
		}
		else
		{	
			printf("x=%lf\n",-c/b);
		}
	}
	else
	{	q=-b/(2*a);
		if(d>0)
		{
			p=sqrt(d)/(2*a);
			printf("x1=%lf\nx2=%lf\n",q+p,q-p);
		}
		else if(d==0)
		{	
			if (q==0)
			{
				printf("x1=x2=%lf\n",-q);
			}
			else
			{
				printf("x1=x2=%lf\n",q);
			}
		}
		else
		{	
			p=sqrt(-d)/(2*a);
			if(q==0)
			{
				printf("x1=%lfi\nx2=-%lfi\n",p,p);
			}
			else
			{
				printf("x1=%lf+%lfi\nx2=%lf-%lfi\n",q,p,q,p);
			}
		} 
	}	
	return 0; 
 } 
