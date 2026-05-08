#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string, vector<string>> res;
        // for (const auto& s : strs) {
        //     vector<int> count(26, 0);
        //     for (char c : s) {
        //         count[c - 'a']++;
        //     }
        //     string key = to_string(count[0]);
        //     for (int i = 1; i < 26; ++i) {
        //         key += ',' + to_string(count[i]);
        //     }
        //     res[key].push_back(s);
        // }
        // vector<vector<string>> result;
        // for (const auto& pair : res) {
        //     result.push_back(pair.second);
        // }
        // return result;        
        
        vector<vector<string>> output;
        //create the map of the sorted string and the string vector, for grouping the anagrams
        unordered_map<string, vector<string>> anagram;
        string sorted_string;
        for(int i = 0 ; i < strs.size() ; i++){
            sorted_string = strs[i];
            sort(sorted_string.begin(), sorted_string.end());
            // if the same anagram exists, push back to the corresponding vector
            if(anagram.count(sorted_string)){
                anagram.find(sorted_string)->second.push_back(strs[i]);
            }
            // if the anagram is new, create a new pair in the map
            else{
                vector<string> new_group;
                new_group.push_back(strs[i]);
                anagram[sorted_string] = new_group;
            }
        }
        // complete the output vector<vector<string>>
        for(auto& ag : anagram){
            output.push_back(ag.second);
        }
        return output;
    }
};
