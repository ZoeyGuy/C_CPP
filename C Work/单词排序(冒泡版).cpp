#include"stdio.h"
#include"string.h"
int main()
{
	int i,j,c;
	char s[5][10]={'\0'};
	char temp[10];
	for(i=0;i<5;i++) scanf("%s",s[i]);
	for(i=0;i<4;i++)  //��סð�����򷨵Ļ������������� 
		for(j=0;j<5-i;j++) 
		{
			c=strcmp(s[j],s[i]);//�ȽϺ�����ǰ�ߴ������������ͬ���0 
			if(c>0) 
			{
				strcpy(temp,s[i]);  //�ַ�����λ��������� 
				strcpy(s[i],s[j]);  //һ��һ������ֱ�Ӹ�ֵ������ 
				strcpy(s[j],temp);
			} 
		}
	for(i=0;i<5;i++)  printf("%s\n",s[i]);
	return 0;
}
