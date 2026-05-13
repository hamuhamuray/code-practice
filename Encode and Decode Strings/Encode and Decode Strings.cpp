#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(string str: strs){
            //Get the length of each string, then pad the length into three digits
            int length = str.size();
            string ns;
            if(length == 0){
                ns = "000";
            }
            else if(length < 10){
                ns = "00" + to_string(length);
            }
            else if(length < 100){
                ns = "0" + to_string(length);
            }
            else{
                ns = to_string(length);
            }

            //Add ns in front of each string, then combine the strings
            encoded_string += ns;
            encoded_string += str;  
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        int current = 0;
        for(int i = 0 ; i < s.size(); i = current + 1){
            //Get the length of each string
            string ns = s.substr(i, 3);
            int length = stoi(ns);
            
            //Use the length to restore the string
            string str;
            //Check if length equals to 0
            if(length == 0){
                decoded_string.push_back(str);
                current = i + 2;
                continue;
            }
            
            for(int j = i + 3 ; j < i + 3 + length ; j++){
                str += s[j];
                current = j;
            }
            decoded_string.push_back(str);
        }
        return decoded_string;
    }
};

