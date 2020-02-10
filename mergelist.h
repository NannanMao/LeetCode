//
// Created by lenovo on 2020/2/8.
//

#ifndef LEETCODE_MERGELIST_H
#define LEETCODE_MERGELIST_H

#include <stdlib.h>
#include <stdio.h>
#include "listnode.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    struct ListNode *pHead=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p=pHead,*p1=l1,*p2=l2;
    while(p1 && p2){
        if(p1->val < p2->val){
            p->next=p1;
            p1=p1->next;
        }else{
            p->next=p2;
            p2=p2->next;
        }
        p=p->next;
    }
    while(p1){
        p->next=p1;
        p1=p1->next;
        p=p->next;
    }
    while(p2){
        p->next=p2;
        p2=p2->next;
        p=p->next;
    }
    p=pHead->next;
    free(pHead);
    return p;
}

#endif //LEETCODE_MERGELIST_H
