#include <string>
#include <vector>
#include <stack>

using namespace std;

void DFS(int curr, int parent, vector<vector<int>>& dp, vector<vector<int>>& adj) {
    dp[curr][0] = 0;
    dp[curr][1] = 1;
    
    for (int& child : adj[curr]) {
        if (child == parent) continue;
        
        DFS(child, curr, dp, adj);
        //if curr has lighthouse, child
        dp[curr][1] += min(dp[child][1], dp[child][0]);
        
        //if curr doesn't, then all children must have it.
        dp[curr][0] += dp[child][1];
    }
    
    return;
    
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    vector<vector<int>> adj(n+1);
    for (auto& edge : lighthouse) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<vector<int>> dp(n+1, vector<int>(2));
    
    DFS(1, 0, dp, adj);
    answer = min(dp[1][0], dp[1][1]);
    
    return answer;
}