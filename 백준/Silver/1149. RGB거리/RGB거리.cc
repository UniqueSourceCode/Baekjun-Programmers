#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int dp[3] = {0};
    int N;
    cin >> N;
    while (N--) {
        int A, B, C;
        cin >> A >> B >> C;
        int d1, d2, d3;
        d1 = dp[0];
        d2 = dp[1];
        d3 = dp[2];
        dp[0] = min(A + d2, A + d3);
        dp[1] = min(B + d1, B + d3);
        dp[2] = min(C + d1, C + d2);
    }
    cout << min(min(dp[0], dp[1]), dp[2]);

    return 0;
}