#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int change(char s[])
{
	int num=0;
	if(strcmp(s,"H1")==0) num=-50;
	else if(strcmp(s,"H2")==0) num=-2;
	else if(strcmp(s,"H3")==0) num=-3;
	else if(strcmp(s,"H4")==0) num=-4;
	else if(strcmp(s,"H5")==0) num=-5;
	else if(strcmp(s,"H6")==0) num=-6;
	else if(strcmp(s,"H7")==0) num=-7;
	else if(strcmp(s,"H8")==0) num=-8;
	else if(strcmp(s,"H9")==0) num=-9;
	else if(strcmp(s,"H10")==0) num=-10;
	else if(strcmp(s,"H11")==0) num=-20;
	else if(strcmp(s,"H12")==0) num=-30;
	else if(strcmp(s,"H13")==0) num=-40;
	else if(strcmp(s,"S12")==0) num=-100;
	else if(strcmp(s,"D11")==0) num=100;
	else if(strcmp(s,"C10")==0) num=0;
	return num;
}
int main()
{
	int n[4]={0};//四个人牌的张数 
	int mark[4]={0};//四个人的分数 
	char s[16][4]={"\0"};
	while(1)
	{
		for(int i=0;i<4;i++) mark[i]=0;
		for(int i=0;i<4;i++)
		{
			int j=0;
			int flag_C=0,flag_S=0,flag_D=0;
			int red_num=0;
			scanf("%d",&n[i]);
			for(j=0;j<n[i];j++)
			{
				scanf("%s",s[j]);
			}
			if(n[i]==1&&strcmp(s[0],"C10")==0) mark[i]=50;
			else
			{
				for(j=0;j<n[i];j++)
				{
					mark[i]+=change(s[j]);
					if(change(s[j])==0)  flag_C=1;
					else if(abs(change(s[j]))<100) red_num++;
					else if(change(s[j])==-100) flag_S=1;
					else if(change(s[j])==100) flag_D=1;
				}
				if(red_num==13)
				{
					mark[i]=200;
					if(flag_S==1&&flag_D==1) mark[i]=500;  //一定要讨论三种情况！！！！！！！！！！！！！！！ 
					else if(flag_S==1&&flag_D==0) mark[i]-=100;
					else if(flag_D==1&&flag_S==0) mark[i]+=100;
					if(flag_C==1) mark[i]=mark[i]*2;
				}
				else
				{
					if(flag_C==1) mark[i]*=2;
				}
			}
		}
		if(n[0]==0&&n[1]==0&&n[2]==0&&n[3]==0) return 0;
		for(int i=0;i<4;i++)
		{
			if(mark[i]>0) printf("+%d",mark[i]);
			else if(mark[i]<0) printf("%d",mark[i]);
			else if(mark[i]==0) printf("0");
			if(i<3) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
