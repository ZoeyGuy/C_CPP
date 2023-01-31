#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int change(char s[])
{
	if(strcmp(s,"one")==0||strcmp(s,"a")==0||strcmp(s,"A")==0||strcmp(s,"Another")==0) return 1;
	else if(strcmp(s,"One")==0||strcmp(s,"another")==0||strcmp(s,"first")==0||strcmp(s,"First")==0) return 1;
	else if(strcmp(s,"two")==0||strcmp(s,"both")==0||strcmp(s,"Both")==0) return 2;
	else if(strcmp(s,"Two")==0||strcmp(s,"second")==0||strcmp(s,"Second")==0) return 2;
	else if(strcmp(s,"three")==0||strcmp(s,"Third")==0) return 3;
	else if(strcmp(s,"Three")==0||strcmp(s,"third")==0) return 3;
	else if(strcmp(s,"four")==0) return 4;
	else if(strcmp(s,"Four")==0) return 4;
	else if(strcmp(s,"five")==0) return 5;
	else if(strcmp(s,"Five")==0) return 5;
	else if(strcmp(s,"six")==0) return 6;
	else if(strcmp(s,"Six")==0) return 6;
	else if(strcmp(s,"seven")==0) return 7;
	else if(strcmp(s,"Seven")==0) return 7;
	else if(strcmp(s,"eight")==0) return 8;
	else if(strcmp(s,"Eight")==0) return 8;
	else if(strcmp(s,"nine")==0) return 9;
	else if(strcmp(s,"Nine")==0) return 9;
	else if(strcmp(s,"ten")==0) return 10;
	else if(strcmp(s,"Ten")==0) return 10;
	else if(strcmp(s,"eleven")==0) return 11;
	else if(strcmp(s,"Eleven")==0) return 11;
	else if(strcmp(s,"twelve")==0) return 12;
	else if(strcmp(s,"Twelve")==0) return 12;
	else if(strcmp(s,"thirteen")==0) return 13;
	else if(strcmp(s,"Thirteen")==0) return 13;
	else if(strcmp(s,"forteen")==0) return 14;
	else if(strcmp(s,"Forteen")==0) return 14;
	else if(strcmp(s,"fifteen")==0) return 15;
	else if(strcmp(s,"Fifteen")==0) return 15;
	else if(strcmp(s,"sixteen")==0) return 16;
	else if(strcmp(s,"Sixteen")==0) return 16;
	else if(strcmp(s,"seventeen")==0) return 17;
	else if(strcmp(s,"Seventeen")==0) return 17;
	else if(strcmp(s,"eigthteen")==0) return 18;
	else if(strcmp(s,"Eigthteen")==0) return 18;
	else if(strcmp(s,"nineteen")==0) return 19;
	else if(strcmp(s,"Nineteen")==0) return 19;
	else if(strcmp(s,"twenty")==0) return 20;
	else if(strcmp(s,"Twenty")==0) return 20;
	else return 0;
}

int main()
{
	char str[10];
	int num[50]={0},i=0;//´¢´æÊý×Ö 
	while(scanf("%s",str)!=EOF)
	{
		int tmp=change(str);
		if(tmp!=0) tmp=(tmp*tmp)%100;
		if(tmp!=0) 
		{
			num[i]=tmp;
			i++;
		}
	}
	if(i==0) 
	{
		printf("0");
		return 0;
	}
	int i_tmp=i;
	while(i_tmp--)
	{
		int min=0;
		for(int j=1;j<i;j++)
		{
			if(num[j]<num[min]) min=j;
		}
		if(min!=0&&num[min]<10) printf("0%d",num[min]);
		else printf("%d",num[min]);
		num[min]=100;
	}
	return 0;
}
