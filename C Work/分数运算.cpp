#include"stdio.h"
int main()
{	int a,b,c,d,e,f,n,e1,f1;
	char s;
	scanf("%d/%d %c %d/%d",&a,&b,&s,&c,&d);
	switch(s)
	{
		case'+':e=a*d+c*b;f=b*d;break;
		case'-':e=a*d-b*c;f=b*d;break;
		case'*':e=a*c;f=b*d;break;
		case'/':e=a*d;f=b*c;break;
	}
	e1=e;f1=f;n=e1%f1; //շת����� 
	while(n!=0)
	{
		e1=f1;  //e1Ϊ��ĸ��e2Ϊ���� 
		f1=n;
		n=e1%f1;
	}
	e=e/f1;f=f/f1;   //�õ������Լ����f1
	//����һЩ�������-----ȫ�����Ҫ������
	if(f==1) printf("%d/%d %c %d/%d = %d\n",a,b,s,c,d,e);   
	else if(e==0) printf("%d/%d %c %d/%d = 0\n",a,b,s,c,d);  
	else if(f<0) printf("%d/%d %c %d/%d = %d/%d\n",a,b,s,c,d,(-1)*e,(-1)*f);
	else printf("%d/%d %c %d/%d = %d/%d\n",a,b,s,c,d,e,f);
	return 0;  
}
