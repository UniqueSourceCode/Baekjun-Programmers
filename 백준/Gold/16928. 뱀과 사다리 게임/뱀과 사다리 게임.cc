#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    map<int, int> ladders;
    for (int i = 0; i < N + M; ++i) {
        int a, b;
        cin >> a >> b;
        ladders[a] = b;
    }
    bool visited[101] = {false};
    int diceroll = 0;

    queue<int> q;
    visited[1] = true;
    q.push(1);
    while (!visited[100]) {
        diceroll++;
        int size = q.size();
        while (size--) {
            int curr = q.front();
            q.pop();
            for (int i = 1; i <= 6; ++i) {
                if ((curr + i) > 100) break;
                if (ladders[curr+i]) {
                    visited[ladders[curr+i]] = true;
                    q.push(ladders[curr+i]);
                    continue;
                }
                if (!visited[curr+i]) {
                    visited[curr+i] = true;
                    q.push(curr+i);
                    continue;
                }
            }
        }
    }
    cout << diceroll;
    return 0;
}