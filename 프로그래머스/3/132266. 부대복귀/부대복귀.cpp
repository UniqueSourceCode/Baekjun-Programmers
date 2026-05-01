#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(int n, int source, int destination, vector<vector<int>>& adj) {
    queue<int> q;
    vector<bool> visited(n+1, false);
    q.push(source);
    visited[source] = true;
    
    int dist = 0;
    while (!q.empty()) {
        if (visited[destination] == true) break;
        dist++;
        int size = q.size();
        while (size--) {
            int curr = q.front(); q.pop();
            for (auto& next : adj[curr]) {
                if (visited[next]) continue;
                
                visited[next] = true;
                q.push(next);
            }
        }
    }
    if (!visited[destination]) return -1;
    else return dist;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> adj(n+1);
    for (auto& road : roads) {
        adj[road[0]].push_back(road[1]);
        adj[road[1]].push_back(road[0]);
    }
    
    for (auto& source : sources) {
        answer.push_back(BFS(n, source, destination, adj));
    }
    
    return answer;
}