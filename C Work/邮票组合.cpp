#include <stdio.h>
int main ()
{
	int a,b,c,d,i,j,k,l;
	static int s[1000];/*����*/
	scanf ("%d%d%d%d",&a,&b,&c,&d);/*����������ֵ��Ʊ*/
	for (i=0;i<=5;i++)
		for (j=0;i+j<=5;j++)/*����ѭ������j���ڿ���b����ֵ��Ʊ��������a����Ʊ+b����Ʊ���5��*/
			for (k=0;k+i+j<=5;k++)
				for (l=0;k+i+j+l<=5;l++)
					s[a*i+b*j+c*k+d*l]++;
	for(i=1;s[i]&&i<=1000;i++);
	printf ("The max is %d.\n",--i);
}
