/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include<iostream>
#include<string>
#include<vector>

using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(auto str: strs){
            string temp = "";
            int i = 0;
            while(prefix[i] == str[i] && i < prefix.size() && i<str.size()){
                temp.push_back(prefix[i]);
                i++;
            }
            prefix = temp;
        }
        return prefix;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> strs = {"ab", "a"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}

