//
// Created by lenovo on 2020/2/8.
//

#ifndef LEETCODE_DELLASTKNODE_H
#define LEETCODE_DELLASTKNODE_H

#include <stdlib.h>
#include "listnode.h"

void delNode(struct ListNode *preNode, struct ListNode *pNode){
    preNode->next=pNode->next;
    pNode->next=NULL;
    free(pNode);
}

int len(struct ListNode *head){
    if(!head){
        return 0;
    }
    int l=0;
    while(head){
        ++l;
        head=head->next;
    }
    return l;
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if(!head || n==0){
        return NULL;
    }
    int l=len(head);
    if(n>l){
        return NULL;
    }
    struct ListNode *p=head;
    if(n==l){
        p=p->next;
        head->next=NULL;
        free(head);
        return p;
    }
    int i=0;
    struct ListNode *pre=head;
    while(i<l-n){
        pre=p;
        p=p->next;
        ++i;
    }
    delNode(pre,p);
    return head;
}

#endif //LEETCODE_DELLASTKNODE_H
