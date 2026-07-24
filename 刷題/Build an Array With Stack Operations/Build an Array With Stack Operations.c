/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    // The size of ans will not exceed n * 2 (Every number is not in target)
    char** ans = malloc(sizeof(char*) * n * 2);
    int curr = 0, size = 0;
    for(int i = 1 ; i <= n ; i++){
        //If i is in target, it only needs to be pushed
        if(i == target[curr]){
            ans[size++] = "Push";
            // printf("%c\n", ans[size - 1][1]);
            curr++;
        }
        //If i isn't in target, it needs to be pushed and popped
        else
        {
            ans[size++] = "Push";
            // printf("%c\n", ans[size - 1][1]);
            ans[size++] = "Pop";
            // printf("%c\n", ans[size - 1][1]);
        }
        //Break the loop if every target is found
        if(curr == targetSize) break;
    }
    // ans = realloc(ans, sizeof(char*) * size);
    *returnSize = size;
    return ans;
}