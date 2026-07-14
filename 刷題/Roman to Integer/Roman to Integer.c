#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    int ans = 0;
    //Add up the numbers according to the Roman numerals
    for(int i = 0 ; i < strlen(s) ; i++){
        switch(s[i]){
            case 'I':
                ans += 1;
                break;
            case 'V':
                ans += 5;
                break;
            case 'X':
                ans += 10;
                break;
            case 'L':
                ans += 50;
                break;
            case 'C':
                ans += 100;
                break;
            case 'D':
                ans += 500;
                break;
            default:
                //s[i] == 'M'
                ans += 1000;
                break;
        }
        // Handle IV, IX, XL, XC, CD and CM
        if(s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ans -= 2;
        else if(s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ans -= 20;
        else if(s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) ans -= 200;
    }
    return ans;

    // LeetCode Solution
    // int t['X' + 1] = {
    //     ['I'] = 1,
    //     ['V'] = 5,
    //     ['X'] = 10,
    //     ['L'] = 50,
    //     ['C'] = 100,
    //     ['D'] = 500,
    //     ['M'] = 1000,
    // };
    // int res = 0;
    // for (int i = 0; s[i]; i++) {
    //     if (t[s[i]] < t[s[i+1]])
    //         res -= t[s[i]];
    //     else
    //         res += t[s[i]];
    // }
    // return res;
}