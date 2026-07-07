#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    // Malloc a new array
    *returnSize = numsSize;
    int* ans = malloc(sizeof(int) * numsSize);
    int pos = 0;
    //n is the position of y1, therefore we can use this to shuffle the array 
    for(int i = 0; i < n ; i++){
        ans[pos] = nums[i];
        ans[pos + 1] = nums[n + i];
        pos += 2;
    }
    return ans;
}