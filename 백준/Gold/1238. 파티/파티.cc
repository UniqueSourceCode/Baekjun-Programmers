#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<pair<int,int>>> edges(N+1);
    vector<vector<pair<int,int>>> reversed_edges(N+1);
    while (M--) {
        int A, B, C;
        cin >> A >> B >> C;
        edges[A].push_back({B, C});
        reversed_edges[B].push_back({A, C});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> dijkstra;
    vector<int> distance_from_party(N+1, 1e9);
    distance_from_party[X] = 0;
    dijkstra.push({0, X});

    while (!dijkstra.empty()) {
        auto [dist, u] = dijkstra.top();
        dijkstra.pop();
        if (distance_from_party[u] < dist) continue;

        for (auto [v, w] : edges[u]) {
            if (distance_from_party[v] > distance_from_party[u] + w) {
                distance_from_party[v] = distance_from_party[u] + w;
                dijkstra.push({distance_from_party[v], v});
            }
        }
    }

    vector<int> distance_to_party(N+1, 1e9);
    distance_to_party[X] = 0;
    dijkstra.push({0, X});

    while (!dijkstra.empty()) {
        auto [dist, u] = dijkstra.top();
        dijkstra.pop();
        if (distance_to_party[u] < dist) continue;

        for (auto [v, w] : reversed_edges[u]) {
            if (distance_to_party[v] > distance_to_party[u] + w) {
                distance_to_party[v] = distance_to_party[u] + w;
                dijkstra.push({distance_to_party[v], v});
            }
        }
    }
    int max_distance = 0;
    for (int i = 1; i<=N; ++i) {
        if (i == X) continue;
        if (max_distance < distance_from_party[i] + distance_to_party[i]) {
            max_distance = distance_from_party[i] + distance_to_party[i];
        }
    }
    cout << max_distance;

    return 0;
}