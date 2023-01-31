#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

#define max 100000

int main()
{
	int amount,num;
	scanf("%d%d",&amount,&num);
	int pri[max],amnt[max];//每位农民的单价和数量 
	for(int i=0;i<num;i++)
	{
		scanf("%d%d",&pri[i],&amnt[i]);
	}
	/*for(int i=0;i<num-1;i++)
	{
		int tmp=i;
		for(int j=i+1;j<num;j++)
		{
			if(pri[j]<pri[i]) tmp=j;
		}
		if(tmp!=i)
		{
			int tmpp1=pri[i];
				pri[i]=pri[tmp]; 
				pri[tmp]=tmpp1;
				 
			int tmpp2=amnt[i];
				amnt[i]=amnt[tmp];
				amnt[tmp]=tmpp2;
		}
	}*/
	
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num-i-1;j++)
		{
			if(pri[j]>pri[j+1])
			{
				int temp1=pri[j];
				pri[j]=pri[j+1];
				pri[j+1]=temp1;
				
				int temp2=amnt[j];
				amnt[j]=amnt[j+1];
				amnt[j+1]=temp2;
			}
		}
	}
	
	//test
//	printf("-----------------------------------------------\n");
//	for(int i=0;i<num;i++) printf("%d  %d\n",pri[i],amnt[i]);
	
	int money_sum=0;
	for(int i=0;i<num;i++)
	{
		amount-=amnt[i];
		if(amount>0) 
		{
			money_sum+=pri[i]*amnt[i];
			continue;
		}
		else if(amount==0) 
		{
			money_sum+=pri[i]*amnt[i];
			break;
		}
		else
		{
			amount+=amnt[i];
			money_sum+=pri[i]*amount;
			break;
		}
	}
	printf("%d",money_sum);
	return 0;
}
