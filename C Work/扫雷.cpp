#include<stdio.h>
#define N 120
int fun(char a[][N],int i,int j)  //定义一个字符串数组及点所在行列坐标 
{ 
	int n1,n2,m1,m2,i1,j1,flag=0,column,row; //i为列；j为行；n1、n2为行边界；m1，m2为列边界。 
	for(i1=0;a[0][i1]!='\0';i1++);column=i1;
	for(j1=0;a[j1][0]!='\0';j1++);row=j1;
//	if(row==1)   //若要限定行数，应当把坐标设为0，而不是1！-----要考虑坐标代入数组 
//	{
//		n1=n2=0;
//	}           //不同的情况一定要用else if 
	if(i==0)  //行列一定要想清楚！！！-----建议画草图 
	{      
		n1=i;n2=i+1;
	}
	else if(i==row-1)
	{
		n1=i-1;n2=i;
	}
	else
	{
		n1=i-1;n2=i+1;
	}
	if(j==0)
	{
		m1=j;m2=j+1;
	}
	else if(j==column-1)
	{
		m1=j-1;m2=j;
	}
	else
	{
		m1=j-1;m2=j+1;
	}
	for(i1=n1;i1<=n2;i1++)
	{
		for(j1=m1;j1<=m2;j1++)
		{
			if(a[i1][j1]=='*') flag++;
		}
	}
	return flag;
}

int main()
{
	int m,n,i=0,j=0,k=0;
	char c[N][N];
	while(scanf("%d %d",&m,&n)&&m&&n) 
	{
		getchar();  //吃掉回车！ ---在按字符一个一个输入时很重要!!! 
		for(i=0; i<m; c[i][j]='\0',i++,getchar())
			for(j=0; j<n; j++) 
				scanf("%c",&c[i][j]);
		for(j=0;j<n;j++) c[i][j]='\0'; //划定边界!!! 
		
		if(k) printf("\n");//把回车看成每次循环的前面，就比较容易判断条件 
		printf("Field #%d:\n",++k);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(c[i][j]=='*') printf("*");
				else printf("%d",fun(c,i,j));
			}
			printf("\n");
		}
	}
	return 0;	
}
