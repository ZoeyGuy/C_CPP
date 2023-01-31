/*这是一个用于输出斐波那契数列第n项的数值的样例*/ 
//可行的原因在于已知了第一,第二项;就可以通过定义数组相加实现 
#include <stdio.h>
#define N 50
void add(int a[],int b[])//定义一个函数实现将整形数组b加到a上,相当于对a数组进行一个操作 
{
	for (int i=0; i<N; i++)
	{
		a[i]+=b[i];
		if (a[i]>9)
		{
			a[i]-=10;
			a[i+1]++;
		}
	}
}
void prt(int a[])//定义一个输出函数 
{
	int i;
	for (i=N-1; a[i]==0; i--);  //去掉前面的零 ,此处用得较巧妙 
	while (i>=0) printf ("%d",a[i--]);
	printf ("\n");
}
int main ()
{
	static int a[N]={1},b[N]={0},n;
	scanf ("%d",&n);
	if (n==0) 
	{
		printf ("0\n");
		return 0;    //终结函数  
	}
	for (int j=0,n1=n>>1; j<n1; j++)  // "n1=n>>1"即将数除以2 
	{
		add(a,b);
		add(b,a);
	}
	if (n&1) //判断n是否为奇数 
	{
		add(a,b);
		prt(a);
	}
	else prt(b);
	return 0; 
}
