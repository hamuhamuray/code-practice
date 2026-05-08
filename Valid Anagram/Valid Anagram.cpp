#include <iostream>
// #include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // if (s.length() != t.length()) {
        //     return false;
        // }

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        
        vector <int> alphabet_s(26), alphabet_t(26);
        for(int i = 0 ; i < s.length() ; i++){
            // Get each character of the string, then record in the vector
            int alphabet_order_s = (int)(s[i] - 'a'); 
            alphabet_s[alphabet_order_s]++;
        }
        for(int i = 0 ; i < t.length() ; i++){
            // Get each character of the string, then record in the vector
            int alphabet_order_t = (int)(t[i] - 'a'); 
            alphabet_t[alphabet_order_t]++;
        }
        // Check if the two vectors are the same, which means the two strings contain the exact same characters
        if(alphabet_s == alphabet_t)return true;
        else return false;
    }
};
