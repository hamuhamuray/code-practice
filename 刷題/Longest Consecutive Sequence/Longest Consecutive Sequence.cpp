#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //NeetCode Solution
        /*
        unordered_map<int, int> mp;
        int res = 0;

        for (int num : nums) {
            if (!mp[num]) {
                mp[num] = mp[num - 1] + mp[num + 1] + 1;
                mp[num - mp[num - 1]] = mp[num];
                mp[num + mp[num + 1]] = mp[num];
                res = max(res, mp[num]);
            }
        }
        return res;
        */      
        
        //Create a unordered_set for the numbers
        unordered_set <int> st;

        for(int i = 0 ; i < nums.size() ; i++){
            st.insert(nums[i]);
        }
        //Alternative: unordered_set<int> store(nums.begin(), nums.end());
        
        //Count the length of the longest consecutive sequence
        int max = 0;
        while(!st.empty()){
            int count = 1, target = *st.begin();
            //Count the number of the increasing consecutive sequence
            int current = target; 
            while(st.count(current + 1)){
                count++;
                //Erase the counted number, but target should be saved for the counting later 
                if(current != target) st.erase(current);
                current++;
            }
            //Count the number of the decreasing consecutive sequence
            current = target; 
            while(st.count(current - 1)){
                count++;
                //Erase the counted number, target will be erased later
                if(current != target) st.erase(current);
                current--;
            }
            //Erase target
            st.erase(target);
            if(max < count) max = count;
        }
        return max;
    }
};
