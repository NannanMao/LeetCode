//
// Created by lenovo on 2020/2/7.
//

#ifndef LEETCODE_THREESUM_H
#define LEETCODE_THREESUM_H

#include <stdlib.h>
#include <stdio.h>


#define NEEDLINES 50000
#define TARGET 0

int cmp(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

int **arr=NULL;

void twoSum(const int *nums, int numsSize, int curSum,int* returnSize,int** returnColumnSizes) {
    if(nums[0]>TARGET-curSum){
        return;
    }
    int l = 0, r = numsSize - 1;
    int leftCur, rightCur;
    while (l < r) {
        if (nums[l] + nums[r] == TARGET - curSum) {
            if(!arr){
                arr=(int**)malloc(sizeof(int*)*NEEDLINES);
            }
            if(!*returnColumnSizes){
                *returnColumnSizes=(int*)malloc(sizeof(int)*NEEDLINES);
            }
            arr[*returnSize]=(int*)malloc(sizeof(int)*3);
            arr[*returnSize][0]=curSum;
            arr[*returnSize][1]=nums[l];
            arr[*returnSize][2]=nums[r];
            (*returnColumnSizes)[*returnSize]=3;
            ++(*returnSize);
            leftCur = nums[l];
            rightCur = nums[r];
            while (l<numsSize && leftCur == nums[l]) {
                ++l;
            }
            while (r>=0 && rightCur == nums[r]) {
                --r;
            }
        } else if (nums[l] + nums[r] > TARGET - curSum) {
            --r;
        } else {
            ++l;
        }
    }
}


int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (!nums || numsSize < 3) {
        return NULL;
    }
    qsort(nums, (size_t) numsSize, sizeof(int), cmp);
    if(nums[0]>TARGET || nums[numsSize-1]<TARGET){
        return NULL;
    }
    int i;
    int curSum;
    i=0;
    while(i<numsSize-2){
        twoSum(nums + i + 1, numsSize - i - 1, nums[i],returnSize,returnColumnSizes);
        curSum=nums[i];
        while(i<numsSize && curSum==nums[i]){
            ++i;
        }
    }
    if(*returnSize) {
        return arr;
    }
    return NULL;
}

void test(){
    int returnSize;
    int *returnColumnSizes;
    int nums[]={0,0,0};
    int numsSize=sizeof(nums)/ sizeof(int);
    int** out=threeSum(nums,numsSize,&returnSize,&returnColumnSizes);
    if(returnSize){
        for(int i=0;i<returnSize;++i){
            for(int j=0;j<returnColumnSizes[i];++j){
                printf("%d ",out[i][j]);
            }
            puts("");
        }
    }
}

#endif //LEETCODE_THREESUM_H
