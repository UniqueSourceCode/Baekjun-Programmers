#include <iostream>
using namespace std;

int grid[500][500];
bool visited[500][500] = {false};
int maxSum = 0;
int N, M;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int inRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        visited[x][y] = false;
        if (sum > maxSum) {
            maxSum = sum;
        }
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (!inRange(x + dx[i], y + dy[i])) continue;
        if (visited[x + dx[i]][y + dy[i]]) continue;
        visited[x + dx[i]][y + dy[i]] = true;
        dfs(x + dx[i], y + dy[i], depth + 1, sum + grid[x + dx[i]][y + dy[i]]);
    }
    visited[x][y] = false;
    return;
}

void checkTshape(int x, int y) {
    int sum = grid[x][y];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == j) continue;
            if (!inRange(x + dx[j], y + dy[j])) break;
            sum += grid[x + dx[j]][y + dy[j]];
        }
        if (maxSum < sum) maxSum = sum;
        sum = grid[x][y];
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int x;
            cin >> x;
            grid[i][j] = x;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = true;
            dfs(i, j, 1, grid[i][j]);
            checkTshape(i, j);
        }
    }
    cout << maxSum;
    return 0;
}