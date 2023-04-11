/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

# include <iostream>
# include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 暴力, 会超时 
    int minSubArrayLen_1(int target, vector<int>& nums) {
        int minLen = INT32_MAX;
        for(size_t i = 0; i<nums.size(); i++){
            int sum = 0;
            for(size_t j = i; j<nums.size(); j++){
                sum += nums[j];
                if(sum >= target){
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                    }
                    break;  // 一旦找到，就跳出，避免超时
                }
            }
        }
        return (minLen==INT32_MAX)? 0 : minLen;
    }
    // 滑动窗口法
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT32_MAX;
        int sum = 0;            // 滑动窗口的数值总和
        int winStartIndex = 0;  // 滑动窗口的起始位置
        int subLen = 0;         // 滑动窗口的长度
        for(int winEndIndex = 0; winEndIndex<nums.size(); winEndIndex++){
            sum += nums[winEndIndex];
            // 这里使用while, 每次更新起始位置, 并不断比较子数组是否符合条件
            while(sum >= target){
                subLen = winEndIndex-winStartIndex+1;
                minLen = (subLen<minLen)? subLen: minLen;
                sum -= nums[winStartIndex];
                winStartIndex++;
            }
        }
        return (minLen==INT32_MAX)? 0 : minLen;
    }
};
// @lc code=end

