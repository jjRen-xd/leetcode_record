#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

    for (int i = 0; i < M; i++) {
        int A, B;
        std::cin >> A >> B;

        for (int j = 0; j < A && j < N; j++) {
            pq.push(B);
            if (pq.size() > N) {
                pq.pop();
            }
        }

        std::vector<int> result;
        std::priority_queue<int, std::vector<int>, std::greater<int> > tempPq = pq;
        while (!tempPq.empty()) {
            result.push_back(tempPq.top());
            tempPq.pop();
        }
        for(int j = result.size() - 1; j >= 0; j--) {
            std::cout << result[j];
        }
        std::cout << std::endl;
    }

    return 0;
}