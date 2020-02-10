//
// Created by lenovo on 2020/2/6.
//

#ifndef LEETCODE_ISMATCH_H
#define LEETCODE_ISMATCH_H

#include <stdio.h>

#define CM(c1,c2) (((c1)==(c2)) || ((c2)=='.'))
int isMatch(char *str, char *pattern){
    char *s=str,*p=pattern;
    if((!s || !*s) && (!p || !*p)){//""和""匹配
        return 1;
    }
    if(!p || !*p){//s没空，但是p空了，false，s空但是p不空有可能匹配，"" 和 ".*"
        return 0;
    }
    if(!s || !*s){//s空了，但是p没空，除非p的下一个字符是'*'且下下个字符是'\0'
        if(p[1]=='*' && !p[2]){
            return 1;
        }
        if(p[1]!='*'){
            return 0;
        }
        return isMatch(s,p+2);
    }


    while(*s && *p && p[1]!='*' && CM(*s,*p)){
        ++s;
        ++p;
    }
    putchar(*s);
    putchar(*p);
    putchar(' ');
    if(!*p){//p空了除非s也空
        return !*s;
    }
    if(!*s){//s空了，但是p没空，除非p的下一个字符是'*'且下下个字符是'\0'
        if(p[1]=='*' && !p[2]){
            return 1;
        }
        if(p[1]!='*'){
            return 0;
        }
        return isMatch(s,p+2);
    }
    if(p[1]!='*'){//p的下一个字符不是'*'，此时要么s空了，要么*s和*p不匹配，两种情况都不匹配
        return 0;
    }
    //接下来的情况是p[1]=='*'
    if(CM(*s,*p)){//当前字符可以匹配上，则匹配一个或者多个或者零个
        return isMatch(s, p + 2) //匹配零个
               || isMatch(s + 1, p + 2) //匹配一个
               || isMatch(s + 1, p); //匹配多个
    }
    //当前字符不能匹配上，匹配零个;
    return isMatch(s, p + 2);
}

#endif //LEETCODE_ISMATCH_H
