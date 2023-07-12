#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int dfs(int curr, unordered_map<int, vector<int>>& parent_map, unordered_map<int, int>& value_map, unordered_map<int, bool>& visited) {
    if (parent_map.find(curr) == parent_map.end() || visited[curr]) {
        return 0;
    }
    visited[curr] = true;
    int max_food = 0;
    for (int neighbor : parent_map[curr]) {
        max_food = max(max_food, dfs(neighbor, parent_map, value_map, visited));
    }
    return max_food + value_map[curr];
}

int getMaxFood(int n, vector<int>& id_list, vector<int>& parent_list, vector<int>& value_list) {
    unordered_map<int, vector<int>> parent_map;
    unordered_map<int, int> value_map;
    for (int i = 0; i < n; i++) {
        int id_num = id_list[i];
        int parent_num = parent_list[i];
        int value = value_list[i];
        parent_map[id_num] = vector<int>();
        value_map[id_num] = value;
        if (parent_num != -1) {
            parent_map[parent_num].push_back(id_num);
        }
    }
    unordered_map<int, bool> visited;
    for (int i : id_list) {
        visited[i] = false;
    }
    int max_food = 0;
    for (int i : id_list) {
        max_food = max(max_food, dfs(i, parent_map, value_map, visited));
    }
    return max_food;
}

int main() {
    // 示例输入
    int n = 3;
    vector<int> id_list = {0,1,2};
    vector<int> parent_list = {-1, 0, 0};
    vector<int> value_list = {3, 1, 2};

    // 调用函数并输出结果
    int max_food = getMaxFood(n, id_list, parent_list, value_list);
    cout << "最多可以获得 " << max_food << " 单位的食物。" << endl;

    return 0;
}
