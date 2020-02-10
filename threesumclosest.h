//
// Created by lenovo on 2020/2/7.
//

#ifndef LEETCODE_THREESUMCLOSEST_H
#define LEETCODE_THREESUMCLOSEST_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

void twoSumClosest(const int* nums,int numsSize,int target,int curSum,int* curClosestSum,
        int* find){
    int l = 0, r = numsSize - 1;
    int minDiff=*curClosestSum==INT_MAX?INT_MAX:abs(target-*curClosestSum);
    int temp;
    while(l<r){
        if((temp=nums[l]+nums[r]+curSum)==target){
            *find=1;
            *curClosestSum=target;
            return;
        }else if(temp<target){
            if(target-temp<minDiff){
                *curClosestSum=temp;
                minDiff=target-temp;
            }
            ++l;
        }else{
            if(temp-target<minDiff){
                *curClosestSum=temp;
                minDiff=temp-target;
            }
            --r;
        }
    }
}

int threeSumClosest(int* nums, int numsSize, int target){
    if(!nums || numsSize<3){
        return 0;
    }
    qsort(nums,(size_t)numsSize,sizeof(int),cmp);
    int find=0,i=0,closestSum=INT_MAX;
    while(i<numsSize-2 && !find){
        twoSumClosest(nums+i+1,numsSize-i-1,target,nums[i],&closestSum,&find);
        ++i;
    }
    if(find){
        return target;
    }
    return closestSum;
}

#endif //LEETCODE_THREESUMCLOSEST_H
