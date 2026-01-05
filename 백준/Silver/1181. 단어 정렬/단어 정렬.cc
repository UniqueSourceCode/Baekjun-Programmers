#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v;
    v.reserve(n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    v.erase(unique(v.begin(), v.end()), v.end());

    for (const auto& s : v) {
        cout << s << "\n";
    }
}