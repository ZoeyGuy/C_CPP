//要求：1000输出000；1输出1，而不是001. 
#include <stdio.h>
int main() 
{
    int n,N,i,r=1,t=1;
    scanf("%d%d",&n,&N);//输入n和N
    n%=1000; //n截取后三位.
    for(i=0;i<N;i++)//循环N次，计算N次乘积----很重要！！！尽量少用pow函数 
    {
    	r=r*n;
    	if(r>1000) {r=r%1000;t=0;}
	}
	if(!t) printf("The last 3 numbers is %d%d%d.", r/100%10,r/10%10,r%10);//输出结果
	else printf("The last 3 numbers is %d.", r);
    return 0;
}
