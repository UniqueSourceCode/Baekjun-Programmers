#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        int T;
        cin >> T;
        unordered_map<string, int> count;
        for (int i = 0; i <T; ++i) {
            string wear;
            cin >> wear;
            cin >> wear;
            count[wear]++;
        }
        int total = 1;
        for (auto [key, value] : count) {
            total = total*(value+1);
        }
        total--;
        cout << total << '\n';
    }
    return 0;
}