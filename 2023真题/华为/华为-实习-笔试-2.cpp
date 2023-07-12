#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int minRegions(int m, int n){
//     vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

//     for(int i = 1; i <= m; i++){
//         for(int j = 1; j <= n; j++){
//             if(i == j){
//                 dp[i][j] = 1;
//             }else{
//                 int minRegions = i * j;
//                 for(int k = 1; k <= i/2; k++){
//                     minRegions = min(minRegions, dp[k][j] + dp[i-k][j]);
//                 }
//                 for(int k = 1; k <= j/2; k++){
//                     minRegions = min(minRegions, dp[i][k] + dp[i][j-k]);
//                 }
//                 dp[i][j] = minRegions;
//             }
//         }
//     }

//     // 打印dp数组
//     for(int i = 1; i <= m; i++){
//         for(int j = 1; j <= n; j++){
//             cout << dp[i][j] << " ";
//         }
//         cout << endl;
//     }
//     // 1 2 3 4
//     // 2 1 3 2
//     // 3 3 1 4
//     // 4 2 4 1
//     // 5 4 4 5
//     // 6 3 2 3
//     return dp[m][n];
// }

int minRegions(int m, int n) {
    // 边界情况，当m或n为1时，返回另一个值
    if (m == 1 || n == 1) {
        return std::max(m, n);
    }

    // 当m和n相等时，只需规划一个正方形区域
    if (m == n) {
        return 1;
    }

    // 尝试在水平方向划分
    int minHorizontal = m*n;
    for (int i = 1; i <= m / 2; ++i) {
        int regions = minRegions(i, n) + minRegions(m - i, n);
        minHorizontal = std::min(minHorizontal, regions);
    }

    // 尝试在垂直方向划分
    int minVertical = n*n;
    for (int i = 1; i <= n / 2; ++i) {
        int regions = minRegions(m, i) + minRegions(m, n - i);
        minVertical = std::min(minVertical, regions);
    }

    // 返回水平和垂直方向划分中的较小值
    return std::min(minHorizontal, minVertical);
}

int main() {
    int m, n;
    std::cin >> m >> n;

    int minRegionsCount = minRegions(m, n);
    std::cout << minRegionsCount << std::endl;

    return 0;
}



