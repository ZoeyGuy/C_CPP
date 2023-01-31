#include <stdio.h>
int main()
{
	double A,B,C;
	scanf("%lf%lf%lf",&A,&B,&C);
    int a,b,c;
    int flag=0;
    for(a=123;a<=789;a++)
    {
        b=(int)a/A*B;
        c=(int)a/A*C;
        if((a/100+a/10%10+a%10+b/100+b/10%10+b%10+c/100+c/10%10+c%10==1+2+3+4+5+6+7+8+9)
		&&((a/100)*(a/10%10)*(a%10)*(b/100)*(b/10%10)*(b%10)*(c/100)*(c/10%10)*(c%10)==1*2*3*4*5*6*7*8*9))
        {
        	printf("%d %d %d\n",a,b,c);
        	flag=1;
		}
    }
    if(flag==0) printf("No!!!\n");
    return 0;
}
