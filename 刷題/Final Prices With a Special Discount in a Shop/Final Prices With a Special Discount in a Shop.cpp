#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Use a monotonic stack to record prices[j], where j is the minimum index such that j > i and prices[j] <= prices[i]
        vector<int> monotonic_stack, prices_after_discount(prices.size());
        for(int i = prices.size() - 1 ; i >= 0 ; i--){
            // Maintain the monotonic stack
            while(monotonic_stack.size() != 0 && prices[i] < monotonic_stack[monotonic_stack.size() - 1]) monotonic_stack.pop_back();
            // Check monotonic_stack to calculate the discount. If monotonic_stack is empty, that means no discount available.
            prices_after_discount[i] = monotonic_stack.size() == 0 ? prices[i] : prices[i] - monotonic_stack[monotonic_stack.size() - 1];
            // Push the current price into the monotonic stack
            monotonic_stack.push_back(prices[i]);
        }
        return prices_after_discount;
    }
};