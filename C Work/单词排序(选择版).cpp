#include <stdio.h>
#include <string.h>
int main()
{
    char a[5][20];
    int i,j,k;
    for(i=0;i<5;i++)  scanf("%s",a[i]);
    for(i=0;i<4;i++)
	{
        k=i;  //初始化！！！ 
        for(j=i+1;j<5;j++)  //注意选择排序法的基本思路！！！ 
		{
            if(strcmp(a[k],a[j])<0)  k=j; //记录最大值的下标 
        } 
        if(k!=i)  //将最大值下标和该轮最前面数的下标互换，实现排序 
		{ 
            char temp[100];
            strcpy(temp, a[k]);
            strcpy(a[k], a[i]);
            strcpy(a[i], temp);
        }
    } 
    for(i=0;i<5;i++)  printf("%s\n",a[i]);
    return 0; 
}

