#include<stdio.h>
int fun1(int a,int b)  //�����Լ���ĺ��� 
{
	int n;
	if(b==0||a==0) return 0;
    else
    {
    	n=a%b;
	    while(n!= 0)     //���� while(n)
	    {
	        a=b;
	    	b=n;
	        n=a%b;
	    }
	    return b;       //ע�����ﷵ�ص���b ����n
	}
}

int fun2(int a,int b)  //����С�������ĺ��� 
{
	int m,n,a1=a,b1=b;
	if(b==0||a==0) return 0;
	else
	{
		n=a%b;
	    while(n!= 0)     //���� while(n)
	    {
	        a=b;
	    	b=n;
	        n=a%b;
	    }
	    m=a1*b1/b;
	    return m;       //ע�����ﷵ�ص���b ����n
	}
} 
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("���Լ����%d\n",fun1(x,y));
	printf("��С��������%d\n",fun2(x,y));
	return 0;
}
