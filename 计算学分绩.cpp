#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("请以“成绩+空格+学分”的格式输入所有的学分绩，以0结尾\n");
    double G[100]; //成绩数组
    double N[100]; //学分数组
    int i=0; //计数器
    double sum_N=0; //学分总和
    double sum_G=0; //学分绩总和
    while (1)
    {
        /* code */
        scanf("%lf%lf",&G[i],&N[i]);
        if(G[i]==0) break;
        sum_N+=N[i];
        sum_G+=N[i]*G[i];
        i++;
    }
    
    double Ave;
    Ave=sum_G/sum_N;
    printf("\n\n你的学分绩为%llf\n\n",Ave);
    system("Pause");
    return 0;
}