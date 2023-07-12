/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include<iostream>
#include<vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIdx = 0;
        for(int fastIdx = 1; fastIdx<nums.size(); fastIdx++){
            if(nums[slowIdx] != nums[fastIdx]){
                nums[++slowIdx] = nums[fastIdx];
            }
        }
        return slowIdx+1;
    }
};
// @lc code=end

