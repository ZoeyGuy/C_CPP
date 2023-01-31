#include <iostream>

using namespace std;

int main()
{
    FILE *fp = NULL;
    char buff[255];
    fp = fopen("./data1.txt", "r");
    fscanf(fp, "%s", buff);
    printf("1: %s\n", buff);
    return 0;
}