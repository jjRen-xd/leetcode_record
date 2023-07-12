/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n)); // 初始化二维数组
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        int num = 1;

        while(left<=right && top<=bottom){
            for(int i = left; i<=right; i++){
                res[top][i] = num++;
            }
            top++;
            for(int i = top; i<=bottom; i++){
                res[i][right] = num++;
            }
            right--;
            for(int i = right; i>=left; i--){
                res[bottom][i] = num++;
            }
            bottom--;
            for(int i = bottom; i>=top; i--){
                res[i][left] = num++;
            }
            left++;
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<vector<int> > res = sol.generateMatrix(5);
    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[0].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}