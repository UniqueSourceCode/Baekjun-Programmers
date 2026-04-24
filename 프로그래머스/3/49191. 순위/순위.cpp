#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> adj1(n+1);
    vector<vector<int>> adj2(n+1);
    for (auto& x : results) {
        adj1[x[0]].push_back(x[1]);
        adj2[x[1]].push_back(x[0]);
    }
    
    vector<int> count(n+1, -1);
    
    stack<int> DFS;
    vector<bool> visited(n+1, false);
    for (int i = 1; i < n+1; ++i) {
        fill(visited.begin(), visited.end(), false);
        DFS.push(i);
        visited[i] = true;
        while (!DFS.empty()) {
            int x = DFS.top(); DFS.pop();
            count[i]++;
            for (int next : adj1[x]) {
                if (visited[next]) continue;
                DFS.push(next);
                visited[next] = true;
            }
        }
    }
    
    for (int i = 1; i < n+1; ++i) {
        fill(visited.begin(), visited.end(), false);
        DFS.push(i);
        visited[i] = true;
        while (!DFS.empty()) {
            int x = DFS.top(); DFS.pop();
            count[i]++;
            for (int next : adj2[x]) {
                if (visited[next]) continue;
                DFS.push(next);
                visited[next] = true;
            }
        }
    }
    
    for (int i = 1; i < n+1; ++i) {
        if (count[i] == n) answer++;
    }
    
    return answer;
}