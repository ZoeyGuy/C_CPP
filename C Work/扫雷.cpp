#include<stdio.h>
#define N 120
int fun(char a[][N],int i,int j)  //����һ���ַ������鼰�������������� 
{ 
	int n1,n2,m1,m2,i1,j1,flag=0,column,row; //iΪ�У�jΪ�У�n1��n2Ϊ�б߽磻m1��m2Ϊ�б߽硣 
	for(i1=0;a[0][i1]!='\0';i1++);column=i1;
	for(j1=0;a[j1][0]!='\0';j1++);row=j1;
//	if(row==1)   //��Ҫ�޶�������Ӧ����������Ϊ0��������1��-----Ҫ��������������� 
//	{
//		n1=n2=0;
//	}           //��ͬ�����һ��Ҫ��else if 
	if(i==0)  //����һ��Ҫ�����������-----���黭��ͼ 
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
		getchar();  //�Ե��س��� ---�ڰ��ַ�һ��һ������ʱ����Ҫ!!! 
		for(i=0; i<m; c[i][j]='\0',i++,getchar())
			for(j=0; j<n; j++) 
				scanf("%c",&c[i][j]);
		for(j=0;j<n;j++) c[i][j]='\0'; //�����߽�!!! 
		
		if(k) printf("\n");//�ѻس�����ÿ��ѭ����ǰ�棬�ͱȽ������ж����� 
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
