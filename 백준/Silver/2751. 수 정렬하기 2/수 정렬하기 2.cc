#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m;
    cin >> n;
    set<int> unique_numbers;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        unique_numbers.insert(m);
    }
    for (const int& num : unique_numbers) {
        cout << num << "\n";
    }
}