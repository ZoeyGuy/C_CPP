//Ҫ��1000���000��1���1��������001. 
#include <stdio.h>
int main() 
{
    int n,N,i,r=1,t=1;
    scanf("%d%d",&n,&N);//����n��N
    n%=1000; //n��ȡ����λ.
    for(i=0;i<N;i++)//ѭ��N�Σ�����N�γ˻�----����Ҫ��������������pow���� 
    {
    	r=r*n;
    	if(r>1000) {r=r%1000;t=0;}
	}
	if(!t) printf("The last 3 numbers is %d%d%d.", r/100%10,r/10%10,r%10);//������
	else printf("The last 3 numbers is %d.", r);
    return 0;
}
