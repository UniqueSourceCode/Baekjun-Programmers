#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> names;
    string pattern;
    int n, length = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        names.push_back(name);
    }
    pattern = names[0];
    if (n > 1) {
        length = names[0].length();
        for (int i = 0; i < length; ++i) {
            bool match = true;
            for (int j = 1; j < n; ++j) {
                if (pattern[i] != names[j][i]) {
                    match = false;
                    break;
                }
            }
            if (!match) {
                pattern[i] = '?';
            }
        }
    }
    cout << pattern << endl;
    return 0;
}   