//巧妙利用字符串逐个读入再进行比较 
#include <stdio.h>  
#define N 200 
main ()  
{  
    char a[N]={'\0'};
    int i,j,k;
    scanf("%s",a);
    for(i=0;a[i]!=0;i++)
        for(k=i+1;a[k]!=0;k++) 
            if(a[i]<a[k])
            {
                j=a[i];
                a[i]=a[k];
                a[k]=j;
            }  
    printf("%s\n",a);  
}
