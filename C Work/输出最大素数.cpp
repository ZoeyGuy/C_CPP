#include"stdio.h"
#include"math.h"
int main()
{	int a,b,n;
	scanf("%d",&a);
	while(1)
	{
		b=sqrt(a);//�����ַ�������ƽ�� 
		for(;a%b!=0&&b>1;b--);
		//����forѭ�������ֿ���
		if(b==1) { n=a;break;} //һ�� b����һ��˵��a���� 
		else { a--; continue;}//�����ҵ���a�����ϣ����¼�һ 
	}
	printf("The max prime number is %d.\n",n);
	return 0;
} 
