#include<stdio.h>
#include<math.h>

int decide(int n)  //�ж�һ�����Ƿ�Ϊ����,���򷵻�0�����򷵻�1�� 
{
	int n1=sqrt(n);
	int flag=0;
	for(int i=n1;i>=2;i--) 
	{ 
		if(n%i==0) 
		{ 
			flag=1;
			break;
		} 
	} 
	return flag;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<n;j++) //��һ��ѭ�������ٲ��� 
		{                                        //n-i-j>1���ų�����0��1����� 
			if(decide(i)==0&&decide(j)==0&&decide(n-i-j)==0&&n-i-j>1) 
			{
				printf("%d %d %d",i,j,n-i-j);
				return 0;
			}
		}
	}
	return 0;
}
