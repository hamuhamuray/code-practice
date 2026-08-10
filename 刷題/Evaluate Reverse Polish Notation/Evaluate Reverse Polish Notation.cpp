#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a, b;
        for(string s : tokens){
            if(s == "+"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b + a);
            }
            else if(s == "-"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if(s == "*"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b * a);
            }
            else if(s == "/"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b / a);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};