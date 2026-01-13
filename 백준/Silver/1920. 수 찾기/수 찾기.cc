#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n;
    unordered_set<int> unique_numbers;
    unique_numbers.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> m;
        unique_numbers.insert(m);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int query;
        cin >> query;
        if (unique_numbers.find(query) != unique_numbers.end()) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}