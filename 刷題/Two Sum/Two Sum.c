#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b){
    int x = *(int*)a;
    int y = *(int*)b;
    if(x < y)return -1;
    else if(x > y) return 1;
    else return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(*returnSize * sizeof(int));
    int* sorted_nums = malloc(numsSize * sizeof(int));
    memcpy(sorted_nums, nums, numsSize * sizeof(int));
    qsort(sorted_nums, numsSize, sizeof(int), compare);
    int l = 0, r = numsSize - 1, pick_1, pick_2;
    while(l < r){
        if(sorted_nums[l] + sorted_nums[r] == target){
            pick_1 = sorted_nums[l];
            pick_2 = sorted_nums[r];
            break;
        }
        else if(sorted_nums[l] + sorted_nums[r] > target){
            r--;
        }
        else l++;
    }
    int ans_count = 0;
    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] == pick_1 || nums[i] == pick_2){
            result[ans_count] = i;
            ans_count++;
        }
        if(ans_count == 2)break;
    }
    return result;
}

int main(){
    int* array = NULL;
    int size, target;
    scanf("%d %d", &size, &target);
    array = malloc(size * sizeof(int));
    for(int i = 0 ; i < size ; i++){
        scanf("%d", &array[i]);
    }
    int *result = NULL;
    int *returnSize = malloc(sizeof(int));
    result = twoSum(array, size, target, returnSize);
    printf("%d %d", result[0], result[1]);
    free(array);
    free(result);
    free(returnSize);
    return 0;
}