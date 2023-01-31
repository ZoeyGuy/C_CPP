#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	printf("\n请输入你需要算标准偏差的所有数值，并以空格或回车分割，以0结尾\n");
	double N[20];
	int lenth = 0;
	double sum = 0;
	while (1)
	{
		scanf("%lf", &N[lenth]);
		if (N[lenth] == 0)
			break;
		else
			sum += N[lenth];
		lenth++;
	}
	double average;
	average = sum / lenth;
	double S_tmp = 0;
	for (int i = 0; i < lenth; i++)
	{
		S_tmp += (N[i] - average) * (N[i] - average);
	}
	double S; // 标准偏差
	S = sqrt(S_tmp / (lenth - 1));

	printf("\n平均值 Average=");
	printf("%llf\n", average);
	printf("标准偏差（A类不确定度）S(x)=");
	printf("%llf\n", S);
	printf("平均值的A类不确定度 uA(x)=");
	printf("%llf\n\n", S / sqrt(1.0 * (lenth - 1)));

	system("PAUSE");
	return 0;
}
