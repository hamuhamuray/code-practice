#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    int *answer = calloc(temperaturesSize, sizeof(int));
    // Use a monotonic stack to store the indices(dates)
    int *monotonic_stack = malloc(sizeof(int) * temperaturesSize);
    int stack_index = -1;
    monotonic_stack[++stack_index] = 0;
    for(int i = 1 ; i < temperaturesSize ; i++){
        //Check if the current temperature is warmer than those of the indices in the stack
        while(stack_index >= 0 && temperatures[monotonic_stack[stack_index]] < temperatures[i]){
            // Calculate the number of days I have to wait
            answer[monotonic_stack[stack_index--]] = i - monotonic_stack[stack_index];
        }
        // Add the current index into the monotonic stack
        monotonic_stack[++stack_index] = i;
        // The rest of indices in the stack aren't possible to get a warmer temperature
    }
    return answer;

}