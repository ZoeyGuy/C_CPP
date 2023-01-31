#include<stdio.h>
#include<string.h>
#include<math.h>
int main() 
{
	int len_character,len_article;
	int i=0,j=0,k=0,tmp1,tmp2,flag=0;
	int a[10000];
	char character[10],article[1000000];
	
	gets(character);//赋值 
	gets(article);
	
	len_character=strlen(character);
	len_article=strlen(article); 
	
	while(j<len_article) 
	{
		tmp1=character[i]-article[j];
		tmp2=abs(tmp1);
		if(tmp2==0||tmp2==32)  //考虑大小写 
		{
			if(i==len_character-1)
			{
				if(j>=len_character&&(article[j+1]!=' '||article[j-len_character]!=' ')) {i=0;j++;} 
				else {i++;j++;}       //考虑到所求单词为一个单词的一部分 
			}
			else {i++;j++;}
		}
		else
		{
			i=0;j++;
		}
		if(i==len_character) //表示单词已遍历完 
		{
			a[k]=j-len_character;
			k++;
			flag++;
			i=0;
		} 
	}
	if(flag==0) printf("-1");
	if(flag!=0) printf("%d %d",flag,a[0]);
	return 0;
}
