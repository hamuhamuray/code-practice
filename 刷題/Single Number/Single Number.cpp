#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // If the number appeared twice, its digits will be toggled twice (cancelled out). Therefore, after toggling all the numbers, the remaining one is the answer 
        int ans = 0;
        for(int& num: nums){
            ans ^= num;
        }
        return ans;
    }
};
