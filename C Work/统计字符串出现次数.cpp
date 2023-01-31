#include <stdio.h>
int main ()
{
	char a[100],b[50];
	int i0=0,n=0,i,j;
	gets(a);
	gets(b);
	while (1)
	{
		while (a[i0]!=b[0]) 
		    if (a[i0++]=='\0') 
			{
				if(n==0) printf("No\n");
				else printf ("%d\n",n);
				return 0;
			}
		i=i0;
		j=0;
		while (a[i]!='\0'&&b[j]!='\0')
		{
			if (a[i]==b[j]) 
			{
				i++;
				j++;
			}
		    else break;
		} 
		if (b[j]=='\0') 
		n++;
		i0++;
	}
}
