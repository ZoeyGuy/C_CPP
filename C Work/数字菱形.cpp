//�ص������ҵ�������ֺͺ�������Ĺ�ϵ---�Һ�һ�����ʵı�ţ����� 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{	int a,c,i,j,n;
	scanf("%d",&n);
    for(i=n-1;i>=1-n;i--)  //����� ---��������� 
    {
    	c=0;
    	for(j=1;j<=abs(i);j++) {printf("  ");c++;}
    	for(a=n-1-c;a>=abs(i)-n+1;a--) {printf("%-2d",abs(i)+abs(a)+1);}
    	printf("\n");
	}
	return 0;
}
