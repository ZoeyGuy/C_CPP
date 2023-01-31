#include <stdio.h>
int main ()
{
	int a,b,c,d,i,j,k,l;
	static int s[1000];/*邮资*/
	scanf ("%d%d%d%d",&a,&b,&c,&d);/*输入四种面值邮票*/
	for (i=0;i<=5;i++)
		for (j=0;i+j<=5;j++)/*例：循环变量j用于控制b分面值邮票的张数，a分邮票+b分邮票最多5张*/
			for (k=0;k+i+j<=5;k++)
				for (l=0;k+i+j+l<=5;l++)
					s[a*i+b*j+c*k+d*l]++;
	for(i=1;s[i]&&i<=1000;i++);
	printf ("The max is %d.\n",--i);
}
