/*
 *给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储 一位 数字。
 *如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 *您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 *示例：
 *输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 *输出：7 -> 0 -> 8 
 *原因：342 + 465 = 807
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int n = 0, m = 0; //个位 进位 //必须初始化为0
    struct ListNode *sum, *p, *q, *r;
    sum = (struct ListNode *)malloc(sizeof(struct ListNode)); //空的头结点
    r = sum;
    p = l1, q = l2;
    while (p != NULL || q != NULL)
    {
        r->next = (struct ListNode *)malloc(sizeof(struct ListNode)); //先有空间才能后移  //否则将踏空
        r = r->next;
        if (p == NULL) //p更短，提前结束
        {
            n = (q->val + m) % 10;
            m = (q->val + m) / 10;
            q = q->next;
        }
        else if (q == NULL) //q更短，提前结束
        {
            n = (p->val + m) % 10;
            m = (p->val + m) / 10;
            p = p->next;
        }
        else //两数等长
        {
            n = (p->val + q->val + m) % 10; //当前个位需要考虑上一个进位
            m = (p->val + q->val + m) / 10; //当前进位需要考虑上一个进位
            q = q->next;
            p = p->next;
        }
        r->val = n;
    }
    if (m > 0) //遗留的最高位进位
    {
        r->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        r = r->next;
        r->val = m;
    }
    r->next = NULL;   //尾部节点赋空值
    return sum->next; //舍弃头部空节点
}

int main(void)
{
    struct ListNode *l1, *l2, *sum, *p;

    //342 (2 -> 4 -> 3)
    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = l1;
    p->val = 9;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 8;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 7;
    p->next = NULL;

    //465 (5 -> 6 -> 4)
    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = l2;
    p->val = 1;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 2;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 3;
    p->next = NULL;

    sum = addTwoNumbers(l1, l2);

    for (p = sum; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    return 0;
}