#include"stdio.h"
int main()
{	int a,b,c,n;   //a,b,c,分别是三种硬币的个数；n为纸币张数 
	scanf("%d",&n);
	if(n%8!=0)  printf("No change.\n");//发现规律：一定要是8的倍数！ 
	else
	{
		a=25*n/4,b=15*n/2,c=45*n/8;
		printf("%d,%d,%d\n",a,b,c);
	}
	return 0;
}
