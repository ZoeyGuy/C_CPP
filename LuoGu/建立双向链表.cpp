#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>


typedef struct DbNode
{
    int data;//结点数据
    DbNode *left;//前驱结点指针
    DbNode *right;//后继结点指针
}DbNode;

//根据数据创建节点
DbNode *CreateNode(int data)
{
    DbNode *pnode = (DbNode *)malloc(sizeof(DbNode));
    pnode->data = data;
    pnode->left = pnode->right = NULL;

    return pnode;
}

//创建链表
DbNode *CreateList(int head)
{
    DbNode *pnode = (DbNode *)malloc(sizeof(DbNode));
    pnode->data = head;
    pnode->left = pnode->right = pnode;

    return pnode;
}

//插入新结点，总是在表尾插入，返回表头结点
DbNode *AppendNode(DbNode *head, int data)
{
    DbNode *node = CreateNode(data);
    DbNode *p = head;

    while (p->right != NULL)
    {   
        p = p->right;
    }
    p->right = node;
    node->left = p;

    return head;
}

int main()
{
    DbNode *head = CreateNode(0);//生成表头，表头数据为0
    for (int i = 1; i < 10; i++)//添加9个节点，数据为1到9
    {
        head = AppendNode(head, i);
    }

    return 0;
}

