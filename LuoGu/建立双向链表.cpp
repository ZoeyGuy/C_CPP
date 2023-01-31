#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>


typedef struct DbNode
{
    int data;//�������
    DbNode *left;//ǰ�����ָ��
    DbNode *right;//��̽��ָ��
}DbNode;

//�������ݴ����ڵ�
DbNode *CreateNode(int data)
{
    DbNode *pnode = (DbNode *)malloc(sizeof(DbNode));
    pnode->data = data;
    pnode->left = pnode->right = NULL;

    return pnode;
}

//��������
DbNode *CreateList(int head)
{
    DbNode *pnode = (DbNode *)malloc(sizeof(DbNode));
    pnode->data = head;
    pnode->left = pnode->right = pnode;

    return pnode;
}

//�����½�㣬�����ڱ�β���룬���ر�ͷ���
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
    DbNode *head = CreateNode(0);//���ɱ�ͷ����ͷ����Ϊ0
    for (int i = 1; i < 10; i++)//���9���ڵ㣬����Ϊ1��9
    {
        head = AppendNode(head, i);
    }

    return 0;
}

