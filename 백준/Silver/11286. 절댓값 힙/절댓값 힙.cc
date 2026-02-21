#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<int> positive;
    priority_queue<int> negative;
    int N;
    cin >> N;
    while (N--) {
        int input;
        cin >> input;
        if (input == 0) {
            if (!positive.empty()) {
                if (!negative.empty()) {
                    if (positive.top() > negative.top()) {
                        cout << -positive.top() << '\n';
                        positive.pop();
                    } else {
                        cout << negative.top() << '\n';
                        negative.pop();
                    }
                } else {
                    cout << -positive.top() << '\n';
                    positive.pop();
                }
            } else if (!negative.empty()) {
                cout << negative.top() << '\n';
                negative.pop();
            } else {
                cout << 0 << '\n';
            }
            continue;
        }
        if (input > 0) {
            positive.push(-input);
        } else {
            negative.push(input);
        }
    }
    return 0;
}