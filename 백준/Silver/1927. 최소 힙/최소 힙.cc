#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<int> max_heap;
    while (n--) {
        int x;
        cin >> x;
        if (x != 0) {
            max_heap.push(-x);
            continue;
        }
        if (max_heap.empty()){
            cout << 0 << "\n";
            continue;
        }
        cout << -max_heap.top() << "\n";
        max_heap.pop();
    }
    return 0;
}