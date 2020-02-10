//
// Created by lenovo on 2020/2/6.
//

#ifndef LEETCODE_TOROMAN_H
#define LEETCODE_TOROMAN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* romans[]={
        "","I","II","III","IV","V","VI","VII","VIII","IX",
        "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
        "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
        "","M","MM","MMM"
};

int numZero(int x){
    int r=0;
    while(x>=10){
        x/=10;
        ++r;
    }
    return r;
}

int minePow10(int n){
    int r=1;
    while(n--){
        r*=10;
    }
    return r;
}

char * intToRoman(int num){
    char* res=(char*)malloc(sizeof(char)*20);
    res[0]=0;
    while(num){
        int n=numZero(num);
        int b= minePow10(n);
        int m=num/b;
        int i=m+n*10;
        strcat(res,romans[i]);
        num=num-m*b;
    }
    return res;
}

#endif //LEETCODE_TOROMAN_H
