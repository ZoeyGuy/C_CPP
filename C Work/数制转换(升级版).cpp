#include <stdio.h>
int main ()
{
	long int pm=0,pn=0,u=1,v=1,p=0,q=0;
	char m[30],n[30];   //存ASCII码
	int a[30],b[30];    //存10进制数
	int i,j,g,k,max1=0,max2=0,flag=0;
	scanf ("%s %s",m,n);
	for (i=0;m[i]!='\0';i++)
		{
			if (m[i]>='A'&&m[i]<='Z') a[i]=m[i]-55;	//m转为10进制存入a
			if (m[i]>='0'&&m[i]<='9') a[i]=m[i]-48;
			max1=(a[i]+1)>max1?(a[i]+1):max1;   //求a的最小进制（最大数+1）
			max1=2>max1?2:max1;
		}
	pm=i;   //求a的位数
	for (j=0;n[j]!='\0';j++)
		{
			if(n[j]>='A'&&n[j]<='Z') b[j]=n[j]-55;
			if(n[j]>='0'&&n[j]<='9') b[j]=n[j]-48;
			max2=(b[j]+1)>max2?(b[j]+1):max2;
			max2=2>max2?2:max2;
		}
	pn=j;
	for (i=max1,j=max2;i<=36&&j<=36;)
		{
			p=0,q=0,u=1,v=1;
			for (g=pm-1;g>=0;g--) {p+=a[g]*u; u*=i;}		//求a的值
			for (k=pn-1;k>=0;k--) {q+=b[k]*v; v*=j;}
			if (p<q) i++;    //若a的进制不够大，则增大
			else if (p>q) j++;
		    else {flag=1; printf ("%s (base %d) = %s (base %d)\n",m,i,n,j); break;}
		}
	if (flag==0) printf("%s is not equal to %s in any base 2..36\n",m,n);
	return 0;
}
