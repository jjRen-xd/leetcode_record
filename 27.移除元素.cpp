/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 暴力解法
    int removeElement_1(vector<int>& nums, int val) {
        size_t numsSize = nums.size();
        for(size_t i = 0; i<numsSize; i++){
            if(nums[i]==val){
                for(size_t j = i+1; j<numsSize; j++){
                    nums[j-1] = nums[j];
                }
                numsSize--;
                i--;
            }
        }
        return numsSize;
    }
    // 双指针
    int removeElement(vector<int>& nums, int val) {
        size_t slowIndex = 0;
        for(size_t fastIndex = 0; fastIndex<nums.size(); fastIndex++){
            if(nums[fastIndex] != val){
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int res = sol.removeElement(nums, val);
    cout << res << endl;
    return 0;
}

