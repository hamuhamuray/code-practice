#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //NeetCode solution: Floyd cycle detection
        /*int turtle = 0, hare = 0;
        turtle = nums[turtle];
        hare = nums[nums[hare]];
        //a: the length between the start of the cycle (duplicate number) and the starting point
        //b: the length from the start of the cycle to the point where turtle and hare meets
        //c: the length from the point where turtle and hare meets to the start of the cycle (the rest of the cycle)
        while(turtle != hare){
            turtle = nums[turtle];
            hare = nums[nums[hare]];
        }
        //Meeting point:
        //turtle: a + b
        //hare: a + k(b + c) + b
        //hare runs twice as fast as turtle: 2(a + b) = a + k(b + c) + b
        // --> a + b = k(b + c)
        // --> a = (k - 1)b + kc = (k - 1)b + (k - 1)c + c = (k - 1)(b + c) + c
        //a ≡ c (mod (b + c, length of the cycle)))
        //If we let turtle and turtle2 (start at the starting point) move at the same time, they will meet at the start of the cycle
        int turtle2 = 0;
        while(turtle != turtle2){
            turtle = nums[turtle];
            turtle2 = nums[turtle2];
        }
        return turtle2;*/
        
        for(int i = 0 ; i < nums.size() ; i++){
            //Check if the value of nums[abs(nums[i]) - 1] is negative, if so, then abs(nums[i]) is the duplicate number
            if(nums[abs(nums[i]) - 1] < 0)return abs(nums[i]);
            //Record the number seen (abs(nums[i])) by changing the value of nums[abs(nums[i]) - 1] to negative
            else nums[abs(nums[i]) - 1] *= -1;
        }
    }
};
