#include"stdio.h"
#include"string.h"
#define N 50 
int main() 
{
	int n,i,j,length,k1=0,k2=0,k3=0,k4=0,tmp1=0,tmp2=0;
	char a[N][N]; 
	scanf("%d",&n); 
	for(i=0;i<n;i++) scanf("%s",a[i]); //将几个密码放到字符串数组里面 
	for(i=0;i<n;i++) 
	{ 
		length=strlen(a[i]);
		if(length<6) printf("Not Safe\n");//长度小于6，直接输出 
		else       
		{
			k1=k2=k3=k4=0;    //ki(1<=i<=4)代表一个密码中四种字符的种数---清零操作！！！ 
			for(j=0;j<length;j++)  //字符遍历 
			{
				if( a[i][j]>=97&&a[i][j]<=122 )    k1++;
				else if( a[i][j]>=48&&a[i][j]<=57 )   k2++;
				else if( a[i][j]>=65&&a[i][j]<=90 )   k3++;
				else   k4++;  
			}
			tmp1=k1*k2||k1*k3||k1*k4||k2*k3||k2*k4||k3*k4;//两两相乘，只要有两个k不为0则tmp1不为0 
			tmp2=k1*k2*k3||k1*k2*k4||k1*k3*k4||k2*k3*k4;//三三相乘，只要有三个k不为0则tmp2不为0 
			if(tmp1==0&&tmp2==0) printf("Not Safe\n");//只有一个k不为0 
			else if(tmp1!=0&&tmp2==0)  printf("Medium Safe\n");//两个k不为0 
			else if(tmp2!=0)  printf("Safe\n");//至少三个k不为0 
		}
	}
	return 0;
}
