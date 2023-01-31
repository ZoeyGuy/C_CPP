#include"stdio.h"
#include"string.h"
int main()
{
	int i,j,c;
	char s[5][10]={'\0'};
	char temp[10];
	for(i=0;i<5;i++) scanf("%s",s[i]);
	for(i=0;i<4;i++)  //记住冒泡排序法的基本操作！！！ 
		for(j=0;j<5-i;j++) 
		{
			c=strcmp(s[j],s[i]);//比较函数，前者大输出正数，相同输出0 
			if(c>0) 
			{
				strcpy(temp,s[i]);  //字符串换位的特殊操作 
				strcpy(s[i],s[j]);  //一定一定不能直接赋值！！！ 
				strcpy(s[j],temp);
			} 
		}
	for(i=0;i<5;i++)  printf("%s\n",s[i]);
	return 0;
}
