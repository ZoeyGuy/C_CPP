#include"stdio.h"
#include"string.h"
int main()
{
	int n,i,j,k,len;
	char a[25][25];
	scanf("%s",a[0]);
	printf("%s\n",a[0]);
	len=strlen(a[0]);
	for(i=1;i<=len;i++) 
	{
		for(j=0;j<len-1;j++) 
		{
			a[i][j]=a[i-1][j+1];
		} 
		a[i][len-1]=a[i-1][0];	
		for(k=0;k<len;k++)  printf("%c",a[i][k]);//改变思路，按字符串输出 
		printf("\n");
	}
	//for(k=0;k<len+1;k++) printf("%s\n",a[k]);
	return 0;
} 
