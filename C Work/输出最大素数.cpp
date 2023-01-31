#include"stdio.h"
#include"math.h"
int main()
{	int a,b,n;
	scanf("%d",&a);
	while(1)
	{
		b=sqrt(a);//“二分法”即开平方 
		for(;a%b!=0&&b>1;b--);
		//跳出for循环的两种可能
		if(b==1) { n=a;break;} //一， b减到一，说明a符合 
		else { a--; continue;}//二，找到的a不符合，往下减一 
	}
	printf("The max prime number is %d.\n",n);
	return 0;
} 
