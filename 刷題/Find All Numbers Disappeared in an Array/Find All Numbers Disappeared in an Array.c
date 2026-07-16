#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    //Mark the number (nums[i]) seen by change nums[abs(nums[i]) - 1] to negative
    for(int i = 0 ; i < numsSize ; i++){
        if(nums[abs(nums[i]) - 1] > 0){
            //If the number is seen, the size of ans should minus 1 since it contains numbers unseen
            (*returnSize)--;
            nums[abs(nums[i]) - 1] *= -1;
        } 
    }
    int *ans = malloc(sizeof(int) * *returnSize);
    int curr = 0;
    //Put the index which nums[i] > 0 into ans
    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] > 0){
            ans[curr++] = i + 1;
            if(curr == *returnSize)break;
        }
    }
    return ans;
}