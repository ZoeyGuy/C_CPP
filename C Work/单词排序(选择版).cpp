#include <stdio.h>
#include <string.h>
int main()
{
    char a[5][20];
    int i,j,k;
    for(i=0;i<5;i++)  scanf("%s",a[i]);
    for(i=0;i<4;i++)
	{
        k=i;  //��ʼ�������� 
        for(j=i+1;j<5;j++)  //ע��ѡ�����򷨵Ļ���˼·������ 
		{
            if(strcmp(a[k],a[j])<0)  k=j; //��¼���ֵ���±� 
        } 
        if(k!=i)  //�����ֵ�±�͸�����ǰ�������±껥����ʵ������ 
		{ 
            char temp[100];
            strcpy(temp, a[k]);
            strcpy(a[k], a[i]);
            strcpy(a[i], temp);
        }
    } 
    for(i=0;i<5;i++)  printf("%s\n",a[i]);
    return 0; 
}

