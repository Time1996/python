#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

struct LinkList
{
    int date;
    struct LinkList * next;
};

struct LinkList * create_list();//建立一个新表
void insert_LinkList (struct LinkList *, int);//输入添加
void add_LinkList(struct LinkList *, struct LinkList *, struct LinkList *);//合并两个链表
void out_LinkList(struct LinkList *);//输出

int main()
{
    /*
    思路：
            1.建立一个链表LinkList1
            2.当输入不是-1的时候继续录入
            3.当-1的时候结束
            4.建立一个链表LinkList2
            5.合并LinkList1和2到3
            6.排序
     */
    int val;
    struct LinkList * pHead1 = create_list();
    struct LinkList * pHead2 = create_list();
    struct LinkList * pHead3 = create_list();

    while (scanf("%d", &val) && val != -1)
            insert_LinkList(pHead1, val);
    while (scanf("%d", &val) && val != -1)
            insert_LinkList(pHead2, val);
        
        add_LinkList(pHead1, pHead2, pHead3);
        if (pHead3 == NULL)
        {
            printf("NULL");
            return 0;
        }
        out_LinkList(pHead3);

        return 0;
}

struct LinkList * create_list()
{
    struct LinkList * pHead = (struct LinkList *)malloc(sizeof(struct LinkList));
    if (pHead == NULL)
            exit(1);
    pHead->next = NULL;
    pHead->date = NULL;

    return pHead;
}

void insert_LinkLsit(struct LinkList * pHead, int val)
{
    struct LinkList * pNew = (struct LinkList *)malloc(sizeof(struct LinkList));
    struct LinkList * p = pHead;
    while(p->next != NULL)
    {
            p = p->next;
    }
    pNew->date = val;

    struct LinkList * t;
    t = p->next;
    p->next = pNew;
    pNew->next = t;
    
    return;
}

void add_LinkList(struct LinkList * p1, struct LinkList * p2, struct LinkList * p3)
{
    p1 = p1->next;
    p2 = p2->next;
    while (p1 != NULL & p2 != NULL)
    {
        if (p1->date > p2->date)
        {
                p3->next = p2;
                p2 = p2->next;
        }
        else
        {
                p3->next = p1;
                p1 = p1->next;
        }
        p3 = p3->next;
    }
    if (p1 == NULL && p2 == NULL) return;
    if (p1 != NULL)
            p3->next = p1;
    else p1->next =p2;
    return;
}

void out_LinkList(struct LinkList * pHead)
{
    int i  = 1;
    struct LinkList * p = pHead->next;
    while (p != NULL)//这里是不为空,要等到循环到尾节点才为空，循环终止
    {
        if (p->next != NULL)
        printf("%d", p->date);
        if (p->next == NULL)
        printf("%d", p->date);
        i++;
        p = p->next;
    }
    return;
}

