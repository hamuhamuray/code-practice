#include <iostream>
// #include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // if(nums.size() == 0) return 0;
        // sort(nums.begin(), nums.end());
        // for(int i = 0 ; i < nums.size() - 1; i++){
        //     if(nums[i] == nums[i+1]) return 1;
        // }
        // return 0;
        unordered_map <int, int> table;
        for(int i = 0; i < nums.size(); i++){
            if(table.count(nums[i])) return 1;
            table[nums[i]] = nums[i];
        }
        return 0;
    }
};