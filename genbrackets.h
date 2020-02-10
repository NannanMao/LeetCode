//
// Created by lenovo on 2020/2/8.
//

#ifndef LEETCODE_GENBRACKETS_H
#define LEETCODE_GENBRACKETS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void genBrackets(char *str, int leftRemain, int rightRemain, int *returnSize, char **strs, int pos) {
    if (leftRemain == 0 && rightRemain == 0) {
        char *ss = (char *) malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(ss, str);
        strs[*returnSize] = ss;
        ++(*returnSize);
    }
    if (leftRemain > rightRemain) {
        return;
    }
    if (leftRemain > 0) {
        str[pos] = '(';
        str[pos + 1] = 0;
        genBrackets(str, leftRemain - 1, rightRemain, returnSize, strs, pos + 1);
        str[pos] = 0;
    }
    if (rightRemain > 0) {
        str[pos] = ')';
        str[pos + 1] = 0;
        genBrackets(str, leftRemain, rightRemain - 1, returnSize, strs, pos + 1);
        str[pos]=0;
    }
}

int F(int n){
    int b=1;
    while(--n){
        b*=3;
    }
    return (b+1);
}

char **generateParenthesis(int n, int *returnSize) {
    *returnSize=0;
    if(n==0){
        return NULL;
    }
    char** strs=(char**)malloc(sizeof(char*)*F(n));
    char* str=(char*)malloc(sizeof(char)*(2*n+1));
    str[0]=0;
    genBrackets(str,n,n,returnSize,strs,0);
    if(*returnSize){
        return strs;
    }
    return NULL;
}

void test(){
    int returnSize;
    char** strs=generateParenthesis(4,&returnSize);
    if(returnSize){
        for(int i=0;i<returnSize;++i){
            printf("%d ",i+1);
            puts(strs[i]);
        }
    }
}

#endif //LEETCODE_GENBRACKETS_H
