#include"stdio.h"
#include"math.h"
int main()
{	int n,x;
	scanf("%d",&n);
	x=(2*n-3)*pow(2,n-1)+2;//数学建模，套公式 
	if(x>=2) printf("The monkey got %d peaches in first day.\n",x);
	else printf("The monkey got %d peach in first day.\n",x); 
	return 0;
}
