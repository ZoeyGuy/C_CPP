/*��˼·:f(10)=1+f(5)+f(4)+f(3)+f(2)+f(1)*/
/*f(n)=1+f(n/2)+f(n/2-1)+....+f(2)+f(1)*/ 
/*�ݹ��㷨*/
//#include<stdio.h>
//int fun(int n)
//{
//	int flag=0;
//	if(n==1) flag++;
//	else
//	{
//		flag++; 
//		for(int i=1;i<=n/2;i++)
//		{
//			flag+=fun(i);
//		}
//	}
//	return flag;//û�м���ԭ����n/2��,������ǡ����ԭ�������� 
//}
//
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int final=fun(n);
//	printf("%d",final);
//	return 0;
//}

/*�ǵݹ��㷨*/
#include<stdio.h>
int main()
{
	int n,tmp,sum=0;
	scanf("%d",&n);
	if(n==1)                   //��������������� 
	{
		printf("1");return 0;
	}
	else if(n==2||n==3)
	{
		printf("2");return 0;
	}
	int num[100000]={0};
	num[1]=1;
	for(int i=2;i<=n/2;i++)
	{
		tmp=i/2;
		for(int j=tmp;j>=1;j--)
		{
			num[i]+=num[j]; 
		}
		num[i]++;
		sum+=num[i];
	}
	sum+=(num[1]+1);
	printf("%d",sum);
	return 0;
} 
