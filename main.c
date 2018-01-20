#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//前提知识：结构体的创建
/*
typedef struct Student{
    int sid;
    char name[100];
    char gender;
} *PST, ST;



int main() {

    ST stu={1, "wudao", 'm'};

    PST ps = &stu;
    ps->sid=100;
    printf("%d\n",ps->sid);


    return 0;
}*/



//算法：遍历，查找，清空，锢?毁，求长度，排序，插入节点，删除节点


//以下演示一个基本的链表
typedef struct Node
{
    int num;
    struct Node *pNext;
}*PNODE, NODE;

//函数声明
PNODE create_list();
void traverse_list(PNODE pHead);
int is_empty(PNODE);
int length_list(PNODE);//统计长度
void sort_list(PNODE);
int insert_list(PNODE, int, int);//增加节点
int main()
{
    PNODE pHead = NULL;
    int length;
    pHead = create_list();

    traverse_list(pHead);
//    if (is_empty(pHead))
//    {
//        printf("The linked-list is empty!\n");
//    } else {
//        printf("The linked-list is not empty!\n");
//    }
//
//    length = length_list(pHead);
//    printf("The list's length is %d\n", length);
//    sort_list(pHead);
//    traverse_list(pHead);

    insert_list(pHead, 1, 10);
    traverse_list(pHead);
    return 0;
}

PNODE create_list()
{
    int len;
    int i,val;
    //创建一个空的头结点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead)
    {
        printf("Sorry, the memory can't be allocated");
        exit(-1);
    }
    //创建尾指针，让它一直指向最后一个节点
    PNODE pTail = pHead;
    pTail->pNext=NULL;

    printf("Please input the Linked-list's length:");
    scanf("%d", &len);
    for (i=0;i<len;i++)
    {
        printf("Please input the %d's content:",i+1);
        scanf("%d",&val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("Sorry, the memory can't be allocated!\n");
            exit(-1);
        }
        pNew->num = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;//暂时没有下一个节点，所以要留空
        pTail = pNew;//要指向最后一个啊

    }
    return pHead;
}


void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;//头节点是空的，一定要加上->pNext;
    while(NULL != p)
    {
        printf("%d ",p->num);
        p = p->pNext;
    }
    return;
}

int is_empty(PNODE pHead)
{
    if(NULL == pHead->pNext)
    {
        return 1;
    } else {
        return 0;
    }
}
int length_list(PNODE pHead)
{
    PNODE p = pHead->pNext;//头节点是空的，一定要加上->pNext从而指向首节点;
    int sum=0;
    while(NULL != p)
    {
        sum++;

        p = p->pNext;
    }
    return sum;
}

void sort_list(PNODE pHead)
{
    PNODE p,q;
    int t;
    int len = length_list(pHead);

    for (p=pHead->pNext;p!=NULL;p=p->pNext)
    {
        for (q=p->pNext;q!=NULL;q=q->pNext)
        {
            if(p->num > q->num)
            {
                t = p->num;
                p->num = q->num;
                q->num = t;
            }
        }
    }
    return;

}

int insert_list(PNODE pHead, int pos, int val)
{
    PNODE p = pHead, pNew, q;
    int i=0;
    //关键算法
    while (NULL != p && i<pos-1)
    {
        p = p->pNext;
        ++i;
    }

    if(i>pos-1 || NULL==p)
        return 0;

    pNew = (PNODE)malloc(sizeof(NODE));

    pNew->num = val;
    q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;

    return 1;
}

//基本链表演示完毕


