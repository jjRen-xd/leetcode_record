// 连续子数组的和等于K的最大长度
// [1,-1,5,-2,3],k=3

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLen(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int sum = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum == k) {
            res = i + 1;
        } else if (m.find(sum - k) != m.end()) {
            res = max(res, i - m[sum - k]);
        }
        if (m.find(sum) == m.end()) {
            m[sum] = i;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    cout << maxLen(nums, k) << endl;
    return 0;
}