/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<iostream>
#include<vector>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if((nums[i] + nums[j]) == target){
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

