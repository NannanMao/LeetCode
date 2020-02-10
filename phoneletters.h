//
// Created by lenovo on 2020/2/7.
//

#ifndef LEETCODE_PHONELETTERS_H
#define LEETCODE_PHONELETTERS_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


char *letters[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void getLetterCombinations(char* digitsPtr,char** strs,int* returnSize,int curPos,char* str){
    if(!*digitsPtr){
        char* ss=(char*)malloc(sizeof(char)*(strlen(str)+1));
        strcpy(ss,str);
        strs[*returnSize]=ss;
        ++(*returnSize);
        return;
    }
    char* curLetters=letters[(*digitsPtr)-'0'];
    //printf("%d %s %d\n",curPos,curLetters,*returnSize);
    for(int i=0;i<strlen(curLetters);++i){
//        printf("%c %d %d\n",curLetters[i],*returnSize,curPos);
        str[curPos]=curLetters[i];
        str[curPos+1]=0;
        getLetterCombinations(digitsPtr+1,strs,returnSize,curPos+1,str);
        str[curPos]=0;
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    *returnSize=0;
    if(!digits || !*digits){
        return NULL;
    }
    int maxSize=1;
    char* p=digits;
    while(*p){
        maxSize*=strlen(letters[(*p++)-'0']);
    }
//    printf("%d\n",maxSize);
    char** strs=(char**)malloc(sizeof(char*)*(maxSize+1));
    //char** strPtrs=(char**)malloc(sizeof(char*));
    int i=0;
//    for(i=0;i<maxSize;++i){
//        strs[i]=(char*)malloc(sizeof(char)*(strlen(digits)+1));
//        strs[i][0]=0;
//    }
    char* str=(char*)malloc(sizeof(char)*(strlen(digits)+1));
    str[0]=0;
    int curPos=0;
    getLetterCombinations(digits,strs,returnSize,curPos,str);
    return strs;
}

//void test(){
//    char* digits="79";
//    int returnSize;
//    char** strs=letterCombinations(digits,&returnSize);
//    if(returnSize){
//        for(int i=0;i<returnSize;++i){
//            puts(strs[i]);
//        }
////        puts(strs[0]);
//    }
//}

#endif //LEETCODE_PHONELETTERS_H
