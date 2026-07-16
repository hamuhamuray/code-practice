#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b){
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;

    if(int_a < int_b) return -1;
    else if(int_a > int_b)return 1;
    else return 0;
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    // Use an array to record the order of the numbers in nums
    int order[101];
    memset(order, -1, sizeof(order));
    // Use ans to save the sorted array of nums first
    int *ans = malloc(sizeof(int) * *returnSize);
    memcpy(ans, nums, numsSize * sizeof(int));
    qsort(ans, numsSize, sizeof(int), compare);
    for(int i = 0 ; i < numsSize ; i++){
        // If ans[i] already has an order number, skip it since we only need to know how many numbers are smaller than ans[i], we don't need to count the same numbers
        if(order[ans[i]] == -1)order[ans[i]] = i;
    }
    for(int i = 0 ; i < numsSize ; i++){
        // Then, use ans again to save how many numbers are smaller than each number
        ans[i] = order[nums[i]];
    }
    return ans;
}