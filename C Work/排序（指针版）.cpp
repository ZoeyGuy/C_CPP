#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char change(char c)
{
	char p;
	switch(c)
	{
		case 'a':p='d';break;
		case 'b':p='w';break;
		case 'c':p='k';break;
		case 'd':p=';';break;
		case 'e':p='i';break;
		case 'i':p='a';break;
		case 'k':p='b';break;
		case ';':p='c';break;
		case 'w':p='e';break;
		default :p='0';
	}
	return p;
}

int main()
{
	char s[50];
	gets(s);
	for(int i=0;s[i]!='\0';i++)
	{
		if(change(s[i])!='0') printf("%c",change(s[i]));
		else printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}
