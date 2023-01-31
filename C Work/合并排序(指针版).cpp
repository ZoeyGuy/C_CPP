/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int merge_sort(char *a,char *b,char *c);
int main(int argc, char *argv[]) 
{
	char a[100];
    char b[100];
    char c[200];
	gets(a);
    gets(b);
	merge_sort(a,b,c);
	puts(c);
	return 0;
}
int merge_sort(char *a,char *b,char *c)
{
	char *a1,*b1,*c1;
	a1=a,b1=b,c1=c;
	while(*a1!='\0')  a1++;
	while(*b1!='\0')  b1++;
	while(a<a1&&b<b1) 
	{
		if(*a<*b)
		{
			*c=*a;
			a++;
			c++;
		}
		else
		{
			*c=*b;
			b++;
			c++;
		}
	}
	while(a<a1)
	{
		*c=*a;
		a++;c++;
	}
	while(b<b1)
	{
		*c=*b;
		b++;c++;
	}
	*c='\0';
	return *c1;//可要可不要 
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
