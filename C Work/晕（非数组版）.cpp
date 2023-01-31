#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int g4;
	if (n == 1)
	{
		printf("%3d\n", n);
	}
	else
	{
		for (int b = 1, hang = 1, lie = 1; hang <= n; hang++)
		{
			lie = 1;
			for (; lie <= n; lie++)
			{
				if (hang <= n / 2 + 1)
				{
					g4 = hang - 2;
				}
				else
				{
					g4 = n - hang + 1;
				}
				if (hang == n && lie == 1)
				{
					b = (n - 2) * 3 + 5 - lie;
					printf("%3d", b);
				}
				else if (hang == n)
				{
					b--;
					printf("%3d", b);
				}
				if (hang == 1 && lie == 1)
				{
					printf("%3d", b);
				}
				else if (lie == 1 && hang != n)
				{
					b = (n - 2) * 4 + 6 - hang;
					printf("%3d", b);
				}
				else if (lie <= g4 + 1 && hang != n && 2 * hang <= n + 2)
				{
					b = b + (n - 2 * (lie - 2) - 6) * 4 + 13;
					printf("%3d", b);
				}
				else if (lie <= g4 && hang != n && 2 * hang > n + 2)
				{
					b = b + (n - 2 * (lie - 2) - 6) * 4 + 13;
					printf("%3d", b);
				}
				else if (lie <= n - hang + 1 && 2 * hang <= n && hang != n)
				{
					b++;
					printf("%3d", b);
				}
				else if (n % 2 != 0 && (hang == n / 2 + 1) && (lie == n / 2 + 1))
				{
					b++;
					printf("%3d", b);
				}
				else if (2 * hang > n + 2 && lie < n - g4 + 2 && hang != n && lie != n)
				{
					b--;
					printf("%3d", b);
				}
				else if (lie > n - hang + 1 && hang != n)
				{
					b = b - (n - 2 * (n - lie - 1) - 6) * 4 - 9;
					printf("%3d", b);
				}
				if (lie == n)
				{
					printf("\n");
				}
			}
		}
	}
	return 0;
}
