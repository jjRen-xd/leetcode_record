#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Node {
public:
    int level;
    vector<int> next;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Node> nodes(M);
    unordered_set<int> criticalNodes;

    // 读取阀门所在的层数
    for (int i = 0; i < M; ++i) {
        cin >> nodes[i].level;
    }

    // 读取阀门的可到达阀门编号
    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;
        nodes[i].next.resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> nodes[i].next[j];
        }
    }

    // 遍历阀门，找出关键阀门
    for (int i = 0; i < M; ++i) {
        int level = nodes[i].level;
        bool isCritical = true;
        for (int j = 0; j < nodes[i].next.size(); ++j) {
            int nextNode = nodes[i].next[j];
            if (nodes[nextNode].level <= level) {
                isCritical = false;
                break;
            }
        }
        if (isCritical) {
            criticalNodes.insert(i);
        }
    }

    // 输出关键阀门
    for (auto it = criticalNodes.begin(); it != criticalNodes.end(); ++it) {
        cout << "关键阀门 " << *it << ": " << nodes[*it].level - 1 << endl;
    }

    return 0;
}
