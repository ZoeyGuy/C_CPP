#include"stdio.h"
int main()
{
	int n,i,j,k,plus1,plus2,last;
	char str1[5],str2[5];
	scanf("%d",&n);
	scanf("%s%s",str1,str2);//用字符串代替数字，进行运算 
	plus1 = n+str1[1]+str1[3]+str2[0]+str2[2]+str2[4]-48*5;
	plus2 = str1[0]+str1[2]+str1[4]+str2[1]+str2[3]-48*5;
	last = 9-(plus1*3+plus2-1)%10;
	printf("%d\n",last);
	return 0;
}
