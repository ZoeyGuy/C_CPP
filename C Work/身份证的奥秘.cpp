#include"stdio.h"
#include"string.h"
#define N 100 
int main() 
{ 
	int i,j,l,n,a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}; //放入数组，便于对应 
	int shu,sum,Y;      
	char s[N][20];
	scanf("%d",&n);
	for(i=0;i<n;i++)  scanf("%s",s[i]);
	for(i=0;i<n;i++)
	{
		l=strlen(s[i]);   
		if(l==18)
		{
			sum=0;
			for(j=0;j<l-1;j++)    
			{
				shu=s[i][j]-48;    //shu是指各个字符的十进制数值
				sum+=shu*a[j];
			}
			Y=sum%11;  Y=(12-Y)%11;  //一定要看清楚规律！或者可以考虑再用一个字符串对应起来 
			if(s[i][17]>58)   shu=s[i][17]-78;//出现X的情况 
			else   shu=s[i][17]-48;
			if(Y==shu)   printf("Valid\n");
			else   printf("Invalid\n");
		}
		else if(l==15)
		{
			sum=0;
			if(s[i][12]=='9'&&s[i][13]=='9'&&s[i][14]>='6'&&s[i][14]<='9')
			{
				for(j=0;j<6;j++)  {printf("%c",s[i][j]);sum+=a[j]*(s[i][j]-48);}
				printf("18");  sum+=10;//这里巧妙利用一个一个输出字符来简化输出难度，但还是有点复杂 
				for(j=6;j<l;j++)  {printf("%c",s[i][j]);sum+=a[j+2]*(s[i][j]-48);}
				Y=sum%11;  Y=(12-Y)%11;  
				if(Y==10)  printf("X");
				else  printf("%d",Y);
				printf("\n");
			}
			else
			{
				for(j=0;j<6;j++)  {printf("%c",s[i][j]);sum+=a[j]*(s[i][j]-48);}
				printf("19"); sum+=11;
				for(j=6;j<l;j++)  {printf("%c",s[i][j]);sum+=a[j+2]*(s[i][j]-48);}
				Y=sum%11;  Y=(12-Y)%11; 
				if(Y==10)  printf("X");
				else  printf("%d",Y);
				printf("\n");
			}
		}
		else printf("Invalid\n"); //非法输入很重要！！！！ 
	}
	return 0;
} 
