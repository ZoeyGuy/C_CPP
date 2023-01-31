#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>

void change(int a[][10], int i, int j) //设置一个函数，主要功能是将该点所在行、列、斜都置为2
{
	int len;
	for (len = 0; a[0][len] != 0; len++)//找到数组边界
		;						  
	for (int k = 0; k < len; k++) //行+列
	{
		a[i][k] = 2;
		a[k][j] = 2;
	}
	for (int k = 0; k < len; k++)
	{
		for (int m = 0; m < len; m++)
		{
			if (m - k == j - i || m + k == i + j)
				a[m][k] = 2; //这里可以理解为两条直线：y-x=j-i; y+x=j+i
		}
	}
}

int fun(int a[][10], int i, int flag)
{
	int len;
	int j, num = 0;
	for (len = 0; a[0][len] != 0; len++)
		; //找到数组边界
		  //	if(i==len-1) return;
	for (j = 0; j < len; j++)
	{
		if (a[i][j] == 1)
		{
			if (flag != 0)
				flag--;
			else
			{
				change(a, i, j);
				break;
			}
		}
	}
	
	if (flag != 0)
		return 0;
	if (j == len)
		return fun(a, i - 1, flag + 1);
	else
		return fun(a, i + 1, 0);
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[10][10] = {0};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 1; //置为1，和 0 相区别
	int flag = 0;
	int i, j;
	int som = 0;
	while (som < n)
	{
		for (i = 0; i < n; i++) //行
		{
			for (j = som; j < n; j++)
			{
				if (a[i][j] == 1)
					break;
			}
			if (j == n)
				break;
			change(a, i, j);
		}
		if (i == n)
			flag++;
		som++;
	}
	printf("%d", flag);
	return 0;
}
