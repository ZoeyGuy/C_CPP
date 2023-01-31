//掌握ASCII码值的规律即可 
#include<stdio.h>
main()
{	char x;
	scanf("%c",&x);
	if(x>='A'&&x<='Z')
		x=x+32;
	else if(x>='a'&&x<='z')
		x=x-32;
	else
		x=x;
	printf("%c\n",x);
}

