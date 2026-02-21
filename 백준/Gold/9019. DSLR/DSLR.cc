#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

short D(short x) {
    return (x*2)%10000;
}

short S(short x) {
    return (x > 0) ? x-1 : 9999;
}

short L(short x) {
    int temp = x/1000;
    x = (x*10)%10000;
    x += temp;
    return x;
}

short R(short x) {
    int temp = x%10;
    x = x/10;
    x += temp*1000;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    short T;
    cin >> T;
    char instructions[4] = {'D', 'S', 'L', 'R'};
    while (T--) {
        short A, B;
        bool visited[10000] = {false};
        short back[10000] = {0};
        short step[10000] = {0};
        queue<short> BFS;
        cin >> A >> B;

        visited[A] = true;
        BFS.push(A);
        while (!BFS.empty()) {
            short size = BFS.size();
            while (size--) {
                short curr = BFS.front();
                BFS.pop();
                short nums[4] = {D(curr), S(curr), L(curr), R(curr)};
                for (int i = 0; i<4; ++i) {
                    if (visited[nums[i]]) continue;
                    visited[nums[i]] = true;
                    back[nums[i]] = curr;
                    step[nums[i]] = i;
                    BFS.push(nums[i]);
                }
            }
            if (visited[B]) break;
        }
        stack<short> commands;
        while (B!=A) {
            commands.push(step[B]);
            B = back[B];
        }
        while (!commands.empty()) {
            cout << instructions[commands.top()];
            commands.pop();
        }
        cout << '\n';
    }
    return 0;
}