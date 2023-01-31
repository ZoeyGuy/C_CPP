#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int w(int a, int b, int c)
{
	if(a<=0||b<=0||c<=0) return 1;
	else if(a>20||b>20||c>20) return w(20,20,20);
	else if(a<b&&b<c) return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main()
{
	printf("%d",w(7,1,7));
}
