/*����һ���������쳲��������е�n�����ֵ������*/ 
//���е�ԭ��������֪�˵�һ,�ڶ���;�Ϳ���ͨ�������������ʵ�� 
#include <stdio.h>
#define N 50
void add(int a[],int b[])//����һ������ʵ�ֽ���������b�ӵ�a��,�൱�ڶ�a�������һ������ 
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
void prt(int a[])//����һ��������� 
{
	int i;
	for (i=N-1; a[i]==0; i--);  //ȥ��ǰ����� ,�˴��õý����� 
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
		return 0;    //�սắ��  
	}
	for (int j=0,n1=n>>1; j<n1; j++)  // "n1=n>>1"����������2 
	{
		add(a,b);
		add(b,a);
	}
	if (n&1) //�ж�n�Ƿ�Ϊ���� 
	{
		add(a,b);
		prt(a);
	}
	else prt(b);
	return 0; 
}
