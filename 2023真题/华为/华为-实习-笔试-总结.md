# 第一题

### 1.1 题目

- 工程师小王想要从海量的网络数据中，筛选出忙时数据。由于是海量数据，小王没办法对海量数据进行排序，再取topN的忙时数据(将数据从大到小排序，取前N个)。聪明的小王想到了使用固定大小的优先级队列来进行数据筛选。为了场景简化，我们用正整数集来表示海量的网络数据，同时只取N个忙时数据，也即只取N个最大的正整数。针对每一批数据输入，单独输出一行结果，直接将个正整数拼接完完整的一行字符串输出即可。
- 解答要求
  时间限制： C/C++ 500ms,其他语言：1000ms
  内存限制：C/C++ 100MB,其他语言：200MB

### 1.2 输入输出

- 输入
  第一行是正整数N和M，N为忙时个数，取值范围[1,24]。M为输入的数据行数，范围[1.1000];
  接下来M行，每行两个正整数A,B，以空格分隔，表示有A个重复的正整数B。A、B的取值范围[1,2147483647]，如：
  3 5
  1 5
  6 3
  2 2
  5 4
  1 6

- 输出
  输出每增加一批数据对应的队列结果，直接将队列里的所有数据集从大到小拼接成字符串输出。
  如上例输入的输出为：

  第一次输入1个5,则队列输出为5
  第二次输入6个3,则队列输出为533
  第三次输入2个2,则队列输出为533
  第四次输入5个4,则队列输出为544
  第五次输入1个6,则队列输出为6

  所以最终的输出结果为：
  5
  533
  533
  544
  654

### 1.3 样例

#### 样例1

- 输入：

  1 3
  2 3
  1 6
  7 4

- 输出：

  3
  6
  6

- 解释：

  只保留一个忙时
  第一次输入2个3,则队列输出为3
  第二次输入1个6,则队列输出为6
  第三次输入7个4,则队列输出为6
  所以最终输出结果为:
  3
  6
  6

#### 样例2

- 输入：

  24 3
  10 5
  5 1

  20 8

- 输出：

  5555555555

  555555555511111

  888888888888888888885555

- 解释：

  保留24个忙时数据
  第一次输入10个5,则队列输出为5555555555
  第二次输入5个1,则队列输出为555555555511111
  第三次输入20个8,则队列输出为888888888888888888885555

```c++
// 15%
#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

    for (int i = 0; i < M; ++i) {
        int A, B;
        std::cin >> A >> B;

        for (int j = 0; j < A; ++j) {
            pq.push(B);

            if (pq.size() > N) {
                pq.pop();
            }
        }

        std::stringstream result;
        std::priority_queue<int, std::vector<int>, std::greater<int> > tempPq = pq;
        while (!tempPq.empty()) {
            result << tempPq.top();
            tempPq.pop();
        }

        std::string output = result.str();
        std::reverse(output.begin(), output.end());
        std::cout << output << std::endl;
    }

    return 0;
}
```

![108a12078de5626253d756c36fc44cf](108a12078de5626253d756c36fc44cf.jpg)

# 第二题

### 2.1 题目

- 公司购买一块m×n大小的地皮，用于建设新园区。现要将这块地皮规划为多个正方形区域，出于成本考虑，规划的正方形区域的个数越少越好。即所有区域都应纳入规划，请你帮助计算一下，最少能规划多少区域?
- 时间限制：C/C++ 1000ms,其他语言：2000ms
  内存限制：C/C++256MB,其他语言：5  MB

### 2.2 输入输出

- 输入

  第一行，仅包含一个整数，代表m。
  第二行，仅包含一个整数，代表n。
  其中1<=n<=13， 1<=m<=13

- 输出
  一行，仅包含一个整数，表示最少能规划块区域的数量。

### 2.3 样例

#### 样例1

- 输入：

  3

  2

- 输出：

  3

- 解释：

  最少能规划块3个区域。

  先规划1个2×2

  剩下区成规划2个1×1

#### 样例2

- 输入：

  13

  11

- 输出：

  6

- 解释：

  最少能规划块6个区域。

  先规划1个7×7和1个6×6

  再规划2个4×4和1个5×5

  最后剩下1个1×1

```c++
#include <iostream>
#include <algorithm>

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
    int minHorizontal = m;
    for (int i = 1; i <= m / 2; ++i) {
        int regions = minRegions(i, n) + minRegions(m - i, n);
        minHorizontal = std::min(minHorizontal, regions);
    }

    // 尝试在垂直方向划分
    int minVertical = n;
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

```

![e8022404c16270fd505649822f79ea1](e8022404c16270fd505649822f79ea1.jpg)

# 第三题

### 3.1 题目

某公司计划在A地区选择一片区域投资建设太阳发电站。由于太阳能发电与地形、光照等自然条件强相关，因此在建设前，需要先进行建站选址、确定安装太阳能板的数量，让发电利润最大。

> 发电站每年的利润可以用以下公式计算
> $$
> \sum_{i=0}^N K_i-N\times C
> $$
> 其中：
>
> $K_i$：表示第i个太阳能板的年发电收入，与太阳能板安装位置的自然条件(光照等)有关。
> $N$：表示太阳能板总数量。
> $C$：表示平均每个太阳能板每年的支出费用(老化损耗，维修等)，取固定值：5



整个A地区是一个矩形区域。前期技术人员，按照一块太阳能板覆盖的面积，将A地区内部划分为m\*n个地块。提前勘测并计算出每一个地块的年发电收入，使用m\*n 的发电收入矩阵表示。

为了减少管理成本，充分利用土地，必须选择一个矩形区域进行排列安装。请实现功能，求出发电站应安装多少块太阳能板、年利润最大，最大为多少。

解答要求
时间限制: C/C++ 1000ms.其他语言: 2000ms
内存限制: C/C++ 256MB,其他语言: 512MB

### 3.2 输入输出

- 输入

  第一行包含两个正整数:m,n 空格分隔，表示A地区分成的m*n个地块；0<m、n<1024。
  后续 n 行，每行 m 个正整数、空格分隔。表示每个小块区域的太阳能板年发电收入。0<= 收入<100。

- 输出

  两个整数值，空格分隔。第一个值表示安装的太阳能板总量，第二个值表示最大利润。

  - 注意:
    如果存在最大利润相同的情况，则输出太阳能板总量较小的结果。
    如果所有地块利润都是负数，则需选择损失最少的那个地块，安装一块太阳能板。

### 3.3 样例

#### 样例1
- 输入: 
  3 2
  4 10 7
  3 2 9
- 输出: 4 8

- 解释: 
  4 10 7
  3 2 9

  选择的是: 10、7、2、9 这一正方形区域的 4 个地块。
  利润是: ``(10+7+2+9) - (4*5) = 8``

#### 样例2

- 输入: 
  2 2
  1 2
  3 4
- 输出: 1 -1

- 解释: 
  每个地块的利润都是负数，则选择损失最小的一块。选择的是: 10、7、2、9 这一正方形区域的 4 个地块。
  利润是: ``(10+7+2+9) - (4*5) = 8``

```
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> m >> n;
    vector<vector<int>> G(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }

    int max_profit = -1e9; // 初始值设为极小值
    int num_elements = 0;
    int sum_elements = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    int elements = (k - i + 1) * (l - j + 1);
                    int sum = 0;
                    for (int p = i; p <= k; p++) {
                        for (int q = j; q <= l; q++) {
                            sum += G[p][q];
                        }
                    }
                    int profit = sum - elements*5;
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
```

```
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    std::cin >> m >> n; // 输入地块的行数m和列数n

    std::vector<std::vector<int>> incomes(n, std::vector<int>(m)); // 创建一个大小为n*m的二维数组，用来存储地块的收入

    // 读取地块的收入矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> incomes[i][j];
        }
    }

    int maxProfit = -1; // 最大利润的初始值设置为-1
    int bestNumPanels = 0; // 最佳太阳能板数量的初始值设置为0

    // 遍历所有可能的矩形区域
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    int numPanels = (k - i + 1) * (l - j + 1); // 计算太阳能板的数量
                    int totalIncome = 0; // 计算总收入的初始值设置为0

                    // 计算当前矩形区域内的总收入
                    for (int x = i; x <= k; x++) {
                        for (int y = j; y <= l; y++) {
                            totalIncome += incomes[x][y];
                        }
                    }

                    int profit = totalIncome - (numPanels * 5); // 计算当前矩形区域的利润

                    // 如果当前利润大于最大利润，或者利润相等但太阳能板数量更小，则更新最优解
                    if (profit > maxProfit || (profit == maxProfit && numPanels < bestNumPanels)) {
                        maxProfit = profit;
                        bestNumPanels = numPanels;
                    }
                }
            }
        }
    }

    std::cout << bestNumPanels << " " << maxProfit << std::endl; // 输出最佳太阳能板数量和最大利润

    return 0;
}

```

可以使用动态规划来优化解决方案，避免使用暴力的枚举方法。

思路如下：

1. 创建一个大小为`n`×`m`的二维数组`dp`，用于存储每个位置的最大利润。
2. 初始化`dp`数组的第一行和第一列为对应位置的收入值。
3. 从第二行和第二列开始，对于每个位置`(i, j)`，计算其最大利润值。
   - 如果`(i, j)`位置的收入为负数，则该位置的最大利润也为负数，表示选择不安装太阳能板。
   - 否则，将`(i, j)`位置的收入加上上方位置`(i-1, j)`和左侧位置`(i, j-1)`的最大利润值，与`(i-1, j-1)`位置的最大利润值相比较，取其中较大的值作为`(i, j)`位置的最大利润。
4. 最后，`dp[n-1][m-1]`即为安装太阳能板的最大利润值，而太阳能板的数量可以通过统计所有非负收入的地块数量得到。

下面是使用动态规划实现的示例代码：

```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    std::cin >> m >> n;

    // 读取每个地块的年发电收入
    std::vector<std::vector<int>> incomes(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> incomes[i][j];
        }
    }

    // 创建动态规划数组，存储每个位置的最大利润
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

    // 初始化第一行和第一列的最大利润
    dp[0][0] = std::max(0, incomes[0][0]);
    for (int i = 1; i < n; i++) {
        dp[i][0] = std::max(0, dp[i-1][0] + incomes[i][0]);
    }
    for (int j = 1; j < m; j++) {
        dp[0][j] = std::max(0, dp[0][j-1] + incomes[0][j]);
    }

    // 计算每个位置的最大利润
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            // 如果收入为负数，则不安装太阳能板
            if (incomes[i][j] < 0) {
                dp[i][j] = 0;
            } else {
                // 取上方、左侧和左上方位置的最大利润，加上当前位置的收入
                dp[i][j] = std::max(0, std::max(dp[i-1][j], dp[i][j-1]) + incomes[i][j]);
            }
        }
    }

    // 计算安装太阳能板的总数
    int numPanels = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (incomes[i][j] >= 0) {
                numPanels++;
            }
        }
    }

    // 输出安装太阳能板的总数和最大利润
    int maxProfit = dp[n-1][m-1];
    std::cout << numPanels << " " << maxProfit << std::endl;

    return 0;
}

```

这种方法的时间复杂度为O(nm)，相较于暴力枚举的O(n^2 * m^2)要更高效。希望这个优化后的代码能满足你的需求。如果还有其他问题，请随时提问。