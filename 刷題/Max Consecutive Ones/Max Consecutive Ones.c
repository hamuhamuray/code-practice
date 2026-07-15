int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int ans = 0, count = 0;
    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] == 1)count++;
        else{
            if(ans < count)ans = count;
            count = 0;
        }
    }
    //Check the last consecutive ones
    if(ans < count)ans = count;
    return ans;
}