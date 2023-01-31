//下面为选择法排序,将小的放前面,每轮只和第一个数交换

for(int i=0;i<a_length-1;i++)  //每一轮都找出该数字及其之后的所有数中的最大（小）值 
{                              //并放到最前面 
	for(int j=i+1;j<a_length;j++)
	{
		if(a[i]>a[j])           
		{
			int temp=a[j];
				a[j]=a[i];
				a[i]=temp;
		}
	}
}
//选择进化版 ——这个版本才是真正的选择排序，上面那个属于“弱化版”，赋值次数和冒泡排序法一样 
for(int i=0;i<a_length-1;i++)  
{
	int p=i;  //记录最大（小）值下标 
	for(int j=i+1;j<a_length;j++)
	{
		if(a[p]>a[j])  p=j; //换下标 
	}
	if(p!=i)    //找到最值后再交换数 
	{
		int tmp=a[i];
			a[i]=a[p];
			a[p]=tmp;
	}
}

//下面为冒泡排序法,将大的放后面,每轮相邻的数两两交换

for (int i = 0; i < a_length; i++) //第一层循环是比的次数 n 
{
    for (int j = 0; j < a_length-i-1; j++) //第二层循环是进行数组中的数两两交换 
	{                                     //而且每一次需要比的次数都比上一次少一 
        if(a[j]>a[j+1])
		{
            int temp = a[j];
            	a[j] = a[j+1];
                a[j+1] = temp;
        }
    }
}
