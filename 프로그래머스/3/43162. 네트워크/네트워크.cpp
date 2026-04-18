#include <string>
#include <vector>

using namespace std;

int DFS(int n, int node, vector<vector<int>> computers, vector<bool>& visited) {
    if (visited[node]) return 0;
    visited[node] = true;
    for (int i = 0; i < n; ++i) {
        if (computers[node][i]) {
            DFS(n, i, computers, visited);
        }
    }
    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        answer += DFS(n, i, computers, visited);
    }
    return answer;
}