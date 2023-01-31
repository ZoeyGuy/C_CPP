#include"stdio.h"
#define N 100
int main()
{
	int a[N],i=0,j;
	while(scanf("%d",&a[i])&&a[i]) i++;
	for(j=1;j<i+1;j++) printf("%d ",a[i-j]);
	return 0;
}
//本题重点在于合理运用scanf的返回值----输出到0截止的一般操作 
