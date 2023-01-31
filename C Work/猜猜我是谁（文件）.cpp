#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	char filename[10];
	int n;
	scanf("%s%d",filename,&n);
	FILE *fp;
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("File Name Error.\n");
		exit(0);
	}
	char s[10][8];
	int i=0;
	while(fgets(s[i],8,fp)!=NULL) i++;
	if(n>i) printf("Line No Error.\n");
	else if(n==i) printf("%s\n",s[n-1]);//最后一行没有回车！！！！！ 
	else printf("%s",s[n-1]);
	fclose(fp);
	return 0;
} 
