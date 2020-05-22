/**
 *题目：给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int * TwoNum=malloc(2*sizeof(int));
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if((nums[i]+nums[j])==target){
                TwoNum[0]=i;
                TwoNum[1]=j;
                *returnSize=2;
                return TwoNum;
            }
        }
    }
    free(returnSize);
    return NULL;
}

int main(void){
    int nums[] = {2, 7, 11, 15}, target = 9;
    int* returnSize;
    int *TwoNum=twoSum(nums,sizeof(nums)/sizeof(int),target,returnSize);
    printf("nums[%d]=%d\nnums[%d]=%d\n%d+%d=%d\n",TwoNum[0],nums[TwoNum[0]],TwoNum[1],nums[TwoNum[1]],nums[TwoNum[0]],nums[TwoNum[1]],nums[TwoNum[0]]+nums[TwoNum[1]]);
    return 0;
}