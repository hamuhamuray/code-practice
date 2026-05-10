#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_map<int, int> count;
        // for (int num : nums) {
        //     count[num]++;
        // }

        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        // for (auto& entry : count) {
        //     heap.push({entry.second, entry.first});
        //     if (heap.size() > k) {
        //         heap.pop();
        //     }
        // }

        // vector<int> res;
        // for (int i = 0; i < k; i++) {
        //     res.push_back(heap.top().second);
        //     heap.pop();
        // }
        // return res;
        
        vector<int> ans;

        //use hash map to store the quantity of the numbers
        unordered_map<int, int> mp;
        for(int& n: nums){
            mp[n]++;
        }
        
        //use bucket sort algorithm to group the numbers based on their frequencies
        vector<vector<int>> frequency(nums.size() + 1);
        for(auto& m: mp){
            frequency[m.second].push_back(m.first);
        }

        //pick the top k frequent numbers
        for(int i = nums.size() ; k > 0 ; i--){
            if(frequency[i].size() != 0){
                for(int& n: frequency[i]){
                    ans.push_back(n);
                    k--;
                }
            }
        }
        return ans;
    }
};
