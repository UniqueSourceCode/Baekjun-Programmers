#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int A, B, C;
    cin >> A >> B >> C;
    long long answer = 1;
    stack<int> bits;
    while (B != 0) {
        bits.push(B & 1);
        B = B >> 1;
    }
    while (!bits.empty()) {
        int bit = bits.top();
        bits.pop();
        answer *= answer;
        answer %= C;
        if (bit == 1) {
            answer *= A;
        }
        answer %= C;
    }
    answer %= C;
    cout << answer;
    return 0;
}