/*����������λ��ʵ�����ֳ�2���2*/ 
#include <stdio.h>
int main ()
{
	int n,sum=0;
	while (scanf ("%d",&n)&&n) 
		sum=sum|(1<<(n-1));
	printf ("%d\n",sum);
}
