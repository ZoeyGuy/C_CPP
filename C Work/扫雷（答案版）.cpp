#include <stdio.h>
#define L 105
int main()
{
	char a[L][L];
	static int b[L][L];
	int m,n,t,i,j,k=0;
	while (1)
	{
		scanf ("%d %d",&m,&n);				//m行n列
		if (m==0||n==0) return 0;
		for (i=0;i<L;i++)					//归零
			for (j=0;j<L;j++)
				b[i][j]=0;
		for (t=1;t<=m;t++)					//存地图
			scanf("%s",&a[t][1]);
		for (i=1;i<=m;i++)					//算雷数
			for (j=1;j<=n;j++)
				if (a[i][j]=='*')
				{
					b[i-1][j-1]++;	b[i-1][ j ]++;	b[i-1][j+1]++;
					b[ i ][j-1]++;					b[ i ][j+1]++;
					b[i+1][j-1]++;	b[i+1][ j ]++;	b[i+1][j+1]++;
				}
		if (k) printf ("\n");				//输出
		printf ("Field #%d:\n",++k);
		for (i=1; i<=m; i++,printf("\n"))
			for (j=1; j<=n; j++)
				if (a[i][j]=='*') printf ("*");
				else  printf ("%d",b[i][j]);
	}
}
