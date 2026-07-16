#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int *ans = malloc(sizeof(int) * *returnSize);
    int sum = 0;
    for(int i = 0 ; i < numsSize ; i++){
        // Mark the numbers seen by changing nums[nums[i] - 1] to negative
        if(nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        else{
            // If the number is negative, it must be the duplicated number
            ans[0] = abs(nums[i]);
        }
        sum += abs(nums[i]);
    }
    // Use the sum to calculate the missing number: the difference between the original sum and the modified sum is the difference of the repetition of one number and loss of another number
    ans[1] = ans[0] + ((1 + numsSize) * numsSize / 2 - sum);
    return ans;
}