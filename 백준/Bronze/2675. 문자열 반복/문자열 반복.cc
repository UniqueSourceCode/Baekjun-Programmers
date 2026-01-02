#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num, length;
        string s;
        cin >> num >> s;
        length = s.length();
        for (int j = 0; j < length; ++j) {
            cout << string(num, s[j]);
        }
        cout << endl;
    }
    return 0;
}