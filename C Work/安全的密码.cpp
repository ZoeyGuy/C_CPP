#include"stdio.h"
#include"string.h"
#define N 50 
int main() 
{
	int n,i,j,length,k1=0,k2=0,k3=0,k4=0,tmp1=0,tmp2=0;
	char a[N][N]; 
	scanf("%d",&n); 
	for(i=0;i<n;i++) scanf("%s",a[i]); //����������ŵ��ַ����������� 
	for(i=0;i<n;i++) 
	{ 
		length=strlen(a[i]);
		if(length<6) printf("Not Safe\n");//����С��6��ֱ����� 
		else       
		{
			k1=k2=k3=k4=0;    //ki(1<=i<=4)����һ�������������ַ�������---������������� 
			for(j=0;j<length;j++)  //�ַ����� 
			{
				if( a[i][j]>=97&&a[i][j]<=122 )    k1++;
				else if( a[i][j]>=48&&a[i][j]<=57 )   k2++;
				else if( a[i][j]>=65&&a[i][j]<=90 )   k3++;
				else   k4++;  
			}
			tmp1=k1*k2||k1*k3||k1*k4||k2*k3||k2*k4||k3*k4;//������ˣ�ֻҪ������k��Ϊ0��tmp1��Ϊ0 
			tmp2=k1*k2*k3||k1*k2*k4||k1*k3*k4||k2*k3*k4;//������ˣ�ֻҪ������k��Ϊ0��tmp2��Ϊ0 
			if(tmp1==0&&tmp2==0) printf("Not Safe\n");//ֻ��һ��k��Ϊ0 
			else if(tmp1!=0&&tmp2==0)  printf("Medium Safe\n");//����k��Ϊ0 
			else if(tmp2!=0)  printf("Safe\n");//��������k��Ϊ0 
		}
	}
	return 0;
}
