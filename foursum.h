//
// Created by lenovo on 2020/2/8.
//

#ifndef LEETCODE_FOURSUM_H
#define LEETCODE_FOURSUM_H

#include <stdlib.h>
#include <stdio.h>

#define NEEDLINES 50000
#define KNUMS 4

int cmp(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

int **arr = NULL;

void twoSum(const int *nums, int numsSize, int curNum0, int curNum1,
            int *returnSize, int **returnColumnSizes,
            int target) {
    if ((nums[0] > 0 || nums[numsSize-1] < 0) && 0==target - curNum0 - curNum1) {
        return;
    }
    int l = 0, r = numsSize - 1;
    int leftCur, rightCur;
    while (l < r) {
        if (nums[l] + nums[r] == target - curNum0 - curNum1) {
            if (!arr) {
                arr = (int **) malloc(sizeof(int *) * NEEDLINES);
            }
            if (!*returnColumnSizes) {
                *returnColumnSizes = (int *) malloc(sizeof(int) * NEEDLINES);
            }
            arr[*returnSize] = (int *) malloc(sizeof(int) * KNUMS);
            arr[*returnSize][0] = curNum0;
            arr[*returnSize][1] = curNum1;
            arr[*returnSize][2] = nums[l];
            arr[*returnSize][3] = nums[r];
            (*returnColumnSizes)[*returnSize] = KNUMS;
            ++(*returnSize);
            leftCur = nums[l];
            rightCur = nums[r];
            while (l < numsSize && leftCur == nums[l]) {
                ++l;
            }
            while (r >= 0 && rightCur == nums[r]) {
                --r;
            }
        } else if (nums[l] + nums[r] > target - curNum0 - curNum1) {
            --r;
        } else {
            ++l;
        }
    }
}


void threeSum(int *nums, int numsSize, int curNum0, int *returnSize, int **returnColumnSizes,
              int target) {
    if ((nums[0] > 0 || nums[numsSize-1] < 0) && 0==target - curNum0) {
        return;
    }
    int i = 0;
    int curNum;
    while (i < numsSize - 2) {
        twoSum(nums + i + 1, numsSize - i - 1, curNum0, nums[i],
               returnSize, returnColumnSizes, target);
        curNum = nums[i];
        while (i < numsSize && curNum == nums[i]) {
            ++i;
        }
    }
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (!nums || numsSize < KNUMS) {
        return NULL;
    }
    qsort(nums, (size_t) numsSize, sizeof(int), cmp);
    if ((nums[0] > 0 || nums[numsSize-1] < 0) && 0==target) {
        return NULL;
    }
    int i = 0;
    int curNum;
    while (i < numsSize - 3) {
        threeSum(nums + i + 1, numsSize - i - 1, nums[i], returnSize, returnColumnSizes, target);
        curNum = nums[i];
        while (i < numsSize && curNum == nums[i]) {
            ++i;
        }
    }
    if (*returnSize) {
        return arr;
    }
    return NULL;
}

void test(){
    int returnSize;
    int *returnColumnSizes;
    int nums[]={1,-2,-5,-4,-3,3,3,5};
    int numsSize=sizeof(nums)/ sizeof(int);
    int target=-11;
    int** out=fourSum(nums,numsSize,target,&returnSize,&returnColumnSizes);
    if(returnSize){
        for(int i=0;i<returnSize;++i){
            for(int j=0;j<returnColumnSizes[i];++j){
                printf("%d ",out[i][j]);
            }
            puts("");
        }
    }
}

#endif //LEETCODE_FOURSUM_H
