#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

int search(char s[], char str[][15])
{
	int i=0;
	for(i=0;str[i]!="0";i++)
	{
		if(strcmp(s,str[i])==0) 
		break;
	}
	return i;
}

/*int main()
{
	char s[10][15];
	for(int i=0;i<5;i++)  scanf("%s",s[i]);
	char c[15];
	scanf("%s",c);
	printf("%d",search(c,s));
}

*/

int main()
{
	int n;
	char s[12][15]={"0"};//用来存放人名 
	char send[12][15]={"0"};//发钱的人 
	char receive[12][15]={"0"};//收钱的人 
	scanf("%d",&n);
	getchar();
	int money[15]={0};
	for(int i=0;i<n;i++)  
	scanf("%s",s[i]);
	int tmp1=0,tmp2=0;
	for(int i=0;i<n;i++)
	{
		int sum=0,num=0;
		scanf("%s",send[i]);
		getchar();
		scanf("%d%d",&sum,&num);
		getchar();
		tmp1=search(send[i],s);
		money[tmp1]-=sum;
		int every=0;
		if(num!=0) every=sum/num;
		for(int j=0;j<num;j++)
		{
			scanf("%s",receive[j]);
			getchar();
			tmp2=search(receive[j],s);
			money[tmp2]+=every;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%s %d\n",s[i],money[i]);
	}
	return 0;
}
