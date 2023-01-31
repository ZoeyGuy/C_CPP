#include<stdio.h>
int main ()
{	float a,b,c,d;
	scanf("%f%f",&a,&c);//数据类型搞清楚即可 
	if(a>=0&&a<=100)
	{	
		if(a>=90&&a<=100)
		{
			b=1.4,d=b*c;
			printf("%.2f\n",d);
		}
		else if(a>=80&&a<90)
		{
			b=1.2,d=b*c;
			printf("%.2f\n",d);
		}
		else if(a>=70&&a<80)
		{
			b=1.1,d=b*c;
			printf("%.2f\n",d);
		}
		else if(a>=60&&a<70)
		{
			b=1,d=b*c;
			printf("%.2f\n",d);
		}
		else if(a>=0&&a<60)
		{
			b=0,d=b*c;
			printf("%.f\n",d);
		}
	}	
	else
	{
		printf("Error.\n"); 
	}
	return 0;
}
