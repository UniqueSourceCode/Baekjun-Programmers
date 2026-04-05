#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int N, M;
vector<queue<int>> child;
vector<int> num_of_parent;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;

    child.resize(N+1, queue<int>());
    num_of_parent.resize(N+1, 0);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        child[u].push(v);
        num_of_parent[v]++;
    }

    for (int i = 1; i < N+1; ++i) {
        if (num_of_parent[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int x = pq.top(); pq.pop();
        cout << x << ' ';

        while (!child[x].empty()) {
            int next = child[x].front(); child[x].pop();
            num_of_parent[next]--;
            if (num_of_parent[next] == 0) {
                pq.push(next);
            }
        }
    }

    return 0;
}