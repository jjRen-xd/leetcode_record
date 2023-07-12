// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> m >> n;
//     vector<vector<int>> G(n, vector<int>(m));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> G[i][j];
//         }
//     }

//     int max_profit = -1e9; // 初始值设为极小值
//     int num_elements = 0;
//     int sum_elements = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             for (int k = i; k < n; k++) {
//                 for (int l = j; l < m; l++) {
//                     int elements = (k - i + 1) * (l - j + 1);
//                     int sum = 0;
//                     for (int p = i; p <= k; p++) {
//                         for (int q = j; q <= l; q++) {
//                             sum += G[p][q];
//                         }
//                     }
//                     int profit = sum - elements*5;
//                     if (profit > max_profit) {
//                         max_profit = profit;
//                         num_elements = elements;
//                         sum_elements = sum;
//                     } else if (profit == max_profit && elements < num_elements) {
//                         num_elements = elements;
//                         sum_elements = sum;
//                     }
//                 }
//             }
//         }
//     }

//     if (max_profit <= 0) {
//         cout << "1 -1" << endl;
//     } else {
//         cout << num_elements << " " << max_profit << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
// 这个程序使用了动态规划的思想，首先计算了矩阵的前缀和，然后使用前缀和快速计算子矩阵中元素的总和。这样，我们就可以在O(n^4)的时间复杂度内解决这个问题。

int main() {
    int n, m;
    cin >> m >> n;
    vector<vector<int>> G(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }

    // 计算前缀和
    vector<vector<int>> preSum(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + G[i - 1][j - 1];
        }
    }

    int max_profit = -1e9;
    int num_elements = 0;
    int sum_elements = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    int elements = (k - i + 1) * (l - j + 1);
                    int sum = preSum[k + 1][l + 1] - preSum[k + 1][j] - preSum[i][l + 1] + preSum[i][j];
                    int profit = sum - elements * 5;
                    if (profit > max_profit) {
                        max_profit = profit;
                        num_elements = elements;
                        sum_elements = sum;
                    } else if (profit == max_profit && elements < num_elements) {
                        num_elements = elements;
                        sum_elements = sum;
                    }
                }
            }
        }
    }

    if (max_profit <= 0) {
        cout << "1 -1" << endl;
    } else {
        cout << num_elements << " " << max_profit << endl;
    }

    return 0;
}
