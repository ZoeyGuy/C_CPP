#include"stdio.h"
int main()
{	
	int i,j,a,b,c,n;
	scanf("%d",&n);
	for(i=0;i<2*n-1;i++)	//�������һ���Ǻ� 
	{
		printf("*");
	}
	printf("\n");
	for(i=2;i<n+1;i++) 
	{
		for(j=1;j<2*n-i+1;j++) 
		{ 
			if(j==i||j==2*n-i)  printf("*");//�ո��ǳ�̬��*�Ǹ�������Կ�����if�ж� 
			else  printf(" ");
		}
		printf("\n");
	}
	return 0;
}
