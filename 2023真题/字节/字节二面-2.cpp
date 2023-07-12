// 有一个整数数组，请找出下标m和n，只要将索引区间[m,n]的元素排好序，
// 整个数组就是有序的。n-m尽量最小，若不存在这样的m和n请返回空
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findUnsortedSubarray(std::vector<int>& nums) {
    std::vector<int> sortedNums(nums);  // 复制原数组
    std::sort(sortedNums.begin(), sortedNums.end());  // 将复制后的数组排序
    // 打印
    for(int i = 0; i<sortedNums.size(); i++){
        std::cout<<nums[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i = 0; i<sortedNums.size(); i++){
        std::cout<<sortedNums[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i = 0; i<sortedNums.size(); i++){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;



    int start = -1;
    int end = -1;

    // 找到无序子数组的起始和结束位置
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != sortedNums[i]) {
            start = i;
            break;
        }
    }
    for (int i = nums.size()-1; i >= 0; i--) {
        if (nums[i] != sortedNums[i]) {
            end = i;
            break;
        }
    }

    // 根据起始和结束位置返回结果
    if (start == -1) {
        return {-1, -1};  // 无序子数组不存在，返回空数组
    } else {
        return {start, end};
    }
}

int main() {
    std::vector<int> nums = {1,2,5,5,5,4,5,6,7,7,8,8,4,6,7,8,9,10,11,12};
    std::vector<int> result = findUnsortedSubarray(nums);

    std::cout << result[0] <<" "<< result[1] << std::endl;

    return 0;
}
