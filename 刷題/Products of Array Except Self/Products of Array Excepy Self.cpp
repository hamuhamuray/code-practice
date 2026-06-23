#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Create vectors to save the total product calculated from the front and back of nums respectively
        vector<int> front_product(nums.size()), back_product(nums.size());
        int front_current = 1, back_current = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            // Save current first, so it won't multiply itself
            front_product[i] = front_current;
            front_current *= nums[i];
        }
        
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            back_product[i] = back_current;
            back_current *= nums[i];
        }
        //Multiply front_product and back_product to calculate the output
        vector<int> output(nums.size());
        for(int i = 0 ; i < nums.size() ; i++){
            output[i] = front_product[i] * back_product[i];
        }

        return output;
    }
};
