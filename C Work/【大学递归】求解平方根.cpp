#include<stdio.h>
#include<math.h>
double Sqrt( double x,double p,double e )
{
	if( fabs( pow(p,2)-x )<e )  return p;
	else return Sqrt(x,0.5*(p+x/p),e);
}

int main()
{
	double x,e;
	scanf("%lf %lf",&x,&e);
	printf("%.8lf\n",Sqrt(x,sqrt(x),e));//此处p可以为任何非零值 
	return 0;
}
