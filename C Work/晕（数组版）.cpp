#include <stdio.h> //顺时针看为正方形abcd 左上角为a
int main()
{
	int a[100][100];
	int n;
	scanf("%d", &n);
	int g = n;
	for (int i = 0, j = 0, b = 1; b <= n * n; g--)
	{
		for (i, j; j <= g - 1; b++, j++) //填 ab
		{
			a[i][j] = b;
		}
		if (j == g) //填bc
		{
			j--;
			i++;
			for (; i <= g - 1; i++, b++)
			{
				a[i][j] = b;
			}
		}
		if (i == g) //填cd
		{
			i--;
			j--;
			for (; j >= n - g; j--, b++)
			{
				a[i][j] = b;
			}
		}
		if (i == g - 1 && n != 2) //填da
		{
			j++;
			i--;
			for (; i > n - g; i--, b++)
			{
				a[i][j] = b;
			}
			i++;
			j++;
		}
	}
	for (int c = 0, d = 0, g1 = 1; g1 <= n * n; g1++, d++) //把数组打出来即可
	{
		printf("%3d", a[c][d]);
		if (d == n - 1)
		{
			printf("\n");
			c++;
			d = -1;
		}
	}
	return 0;
}
