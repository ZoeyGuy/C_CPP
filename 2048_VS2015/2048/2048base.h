#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

void transform(int *p, int len); /*转置*/
void delZeros(int *p, int len, bool rev); /*删除某一行数据中的零元素*/
int combine(int *p, int len, bool rev); /*合并一行数据的相同元素*/
void out(int *p, int len); /*输出二维数组*/
bool ifchange(int *p, int *q, int len); /*判断数组是否改变*/
bool pileRows(int *p, int len, bool rev, bool trans, int *score); /*堆叠数组*/
void AddNum(int *p, int len); /*增加数字*/
void run(int *p, int len, int *score); /*检测按键运行*/

