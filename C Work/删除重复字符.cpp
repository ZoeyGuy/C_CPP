#include"stdio.h"
#include"string.h"
#define N 100
int main()
{
	char s[N];
	int i=0,j=0,k;
	scanf("%s",s);
	for(i=0;s[i+1]!='\0';i++) 
	{ 
		k=i+1;
		for(j=i+1;s[j]!='\0';j++) 
		{
			if(s[j]!=s[i]) 
			{
				s[k]=s[j];
				k++;
			}
		} 
		s[k]='\0';
		//for(k=0;s[k]!='\0';k++) printf("%c",s[k]);
		//printf("\n");
	} 
	for(i=0;s[i]!='\0';i++) printf("%c",s[i]);printf("\n");
	return 0;
}
