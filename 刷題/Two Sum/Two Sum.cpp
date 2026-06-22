#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        // create the map of the num & its position
        unordered_map <int, int> nums_map;
        for(int i = 0 ; i < nums.size() ; i++){
            // if (target - num) is in the map, then we find the two numbers
            if(nums_map.count(target - nums[i])){
                ans[0] = nums_map[target - nums[i]];
                ans[1] = i;
                break;
            }
            // record the num and its position in the map
            nums_map[nums[i]] = i;
        }
        return ans;
    }
};
