/*��¥������,һ�ο�����1�׻�2��*/ 

#include<stdio.h>

long long x[10010],y[10010];

long long Mesch(int i) //Mesch Ϊ Memory search ���仯���� 
{

	int j;

	if(i==1) return 1;

	if(i==2) return 2;

	if(y[i]>0) return y[i]; //���仯���� --------���������ֱ�ӷ��� 

	y[i]=Mesch(i-1)+Mesch(i-2);

	return y[i]; 

}

int main()

{

	int n;

	scanf("%d",&n);

	printf("%I64d",Mesch(n));

}

