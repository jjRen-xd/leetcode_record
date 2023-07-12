/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include<iostream>
#include<string>

using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        bool isPar = true;
        for(int i = 0, j = s.size()-1; i<s.size()/2; i++, j--){
            if(s[i] != s[j]){{
                isPar = false;
                break;
            }}
        }
        return isPar;
    }
};
// @lc code=end

