#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //NeetCode solution: bitwise operation
        /*int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '1';

                if ((rows[r] & (1 << val)) || (cols[c] & (1 << val)) ||
                    (squares[(r / 3) * 3 + (c / 3)] & (1 << val))) {
                    return false;
                }

                rows[r] |= (1 << val);
                cols[c] |= (1 << val);
                squares[(r / 3) * 3 + (c / 3)] |= (1 << val);
            }
        }
        return true;*/
        
        
        //Create the map for the numbers and their corresponding position
        unordered_map<char, vector<vector<bool>>> mp;
        for(int i = 1 ; i <= 9 ; i++){
            mp['0' + i] = vector<vector<bool>> (3, vector<bool> (9, false));
        }

        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                char num = board[i][j];
                //Empty block
                if(num == '.')continue;
                else{
                    //Check which region the number is in
                    int region;
                    if(i <= 2 && j <= 2) region = 0;
                    else if(i <= 2 && j >= 3 && j <= 5) region = 1;
                    else if(i <= 2 && j >= 6) region = 2;
                    else if(i >= 3 && i <= 5 && j <= 2) region = 3;
                    else if(i >= 3 && i <= 5 && j >= 3 && j <= 5) region = 4;
                    else if(i >= 3 && i <= 5 && j >= 6) region = 5;
                    else if(i >= 6 && j <= 2) region = 6;
                    else if(i >= 6 && j >= 3 && j <= 5) region = 7;
                    else region = 8;
                    

                    //Check conflicts
                    if(mp[num][0][i] == true || mp[num][1][j] == true || mp[num][2][region] == true) return false;
                    
                    //Update the map
                    mp[num][0][i] = true;
                    mp[num][1][j] = true;
                    mp[num][2][region] = true;
                    
                }
            }
        }
        return true;
    }
};
