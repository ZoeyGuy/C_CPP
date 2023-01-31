#include<stdio.h>
#include<math.h>
double summar(int n)
{
	double x,sum=0;
	int sum1;
	if(n==1) sum+=1;
	else
	{
		x=1.0/n;
		sum+=x*pow(-1,n);
		sum+=summar(n-1);
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d",&n);
	int tmp=(int)summar(n);
	if(tmp-summar(n)==0) printf("%d\n",tmp);//提供了一种判断double类型数是整数的方法
	 //Another method: 
	             //if( a-(double)((int)a)<1e-8 ) 则为整数;-----两次转换 
	else printf("%lf\n",summar(n));       
	return 0;
}
