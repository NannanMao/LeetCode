//
// Created by lenovo on 2020/2/8.
//

#ifndef LEETCODE_MATCHBRACKETS_H
#define LEETCODE_MATCHBRACKETS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char stack[10000];

void push(char** pStack,char c){
    **pStack=c;
    ++(*pStack);
}

char pop(char** pStack){
    char c=**pStack;
    --(*pStack);
    return c;
}

char top(char* pStack){
    if(pStack==stack){
        return 0;
    }
    return pStack[-1];
}

#define ISL(c) ((c)=='(' || (c)=='[' || (c)=='{')
#define ISR(c) ((c)==')' || (c)==']' || (c)=='}')
#define ISMATCH(c1,c2) ((c1)=='(' && (c2)==')' || (c1)=='[' && (c2)==']' || (c1)=='{' && (c2)=='}')

bool isValid(char * s){
    if(!s || !*s){
        return true;
    }
    char* pStack=stack;
    while(*s){
        if(ISL(*s)){
            push(&pStack,*s);
        }else{
            if(!ISMATCH(top(pStack),*s)){
                return false;
            }else{
                pop(&pStack);
            }
        }
        ++s;
    }
    //printf("%d\n",pStack-stack);
    return pStack==stack;
}

#endif //LEETCODE_MATCHBRACKETS_H
