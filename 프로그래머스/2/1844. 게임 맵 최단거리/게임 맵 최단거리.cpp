#include<vector>
#include <utility>
#include <queue>
using namespace std;


vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int solution(vector<vector<int> > maps)
{
    int answer = 1;
    int m = maps.size();
    int n = maps[0].size();
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (maps[i][j] == 0) visited[i][j] = true;
        }
    }
    queue<pair<int, int>> BFS;
    BFS.push({0, 0});
    visited[0][0] = true;
    while (!BFS.empty() && !visited[m-1][n-1]) {
        answer++;
        int curr_size = BFS.size();
        while (curr_size--) {
            auto [r, c] = BFS.front(); BFS.pop();
            for (auto [dr, dc] : dirs) {
                int new_r = r + dr;
                int new_c = c + dc;
                if (new_r < 0 || new_r > m-1 || new_c < 0 || new_c > n-1) continue;
                if (visited[new_r][new_c]) continue;
                BFS.push({new_r, new_c});
                visited[new_r][new_c] = true;
            }
        }
    }
    if (!visited[m-1][n-1]) return -1;
    return answer;
}