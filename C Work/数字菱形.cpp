//重点在于找到输出数字和横纵坐标的关系---找好一个合适的编号！！！ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{	int a,c,i,j,n;
	scanf("%d",&n);
    for(i=n-1;i>=1-n;i--)  //输出行 ---编号是亮点 
    {
    	c=0;
    	for(j=1;j<=abs(i);j++) {printf("  ");c++;}
    	for(a=n-1-c;a>=abs(i)-n+1;a--) {printf("%-2d",abs(i)+abs(a)+1);}
    	printf("\n");
	}
	return 0;
}
