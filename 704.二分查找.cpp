/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 左闭右闭
    /* 
        47/47 cases passed (28 ms)
        Your runtime beats 81.82 % of cpp submissions
        Your memory usage beats 5.1 % of cpp submissions (27 MB)
    */
    int search(vector<int>& nums, int target) {
        // 定义target在左闭右闭的区间, 即[left, target]
        int left = 0;
        int right = nums.size() - 1;
        // 当left==right时, [left, right]仍然有效, 所以使用 <=
        while(left <= right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }
    // 左闭右开
    /*  
        47/47 cases passed (24 ms)
        Your runtime beats 93.94 % of cpp submissions
        Your memory usage beats 63.93 % of cpp submissions (26.8 MB)
    */
    int search_1(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while(left < right){
            int mid = left+((right-left)>>1);
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }
};
// @lc code=end

