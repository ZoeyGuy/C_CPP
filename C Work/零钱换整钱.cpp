#include"stdio.h"
int main()
{	int a,b,c,n;   //a,b,c,�ֱ�������Ӳ�ҵĸ�����nΪֽ������ 
	scanf("%d",&n);
	if(n%8!=0)  printf("No change.\n");//���ֹ��ɣ�һ��Ҫ��8�ı����� 
	else
	{
		a=25*n/4,b=15*n/2,c=45*n/8;
		printf("%d,%d,%d\n",a,b,c);
	}
	return 0;
}
