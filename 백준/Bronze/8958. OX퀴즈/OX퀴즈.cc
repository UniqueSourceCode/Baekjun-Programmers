#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        int count = 0;
        int points = 0;
        for (const char c : s) {
            if (c == 'O') {
                count++;
            } else count = 0;
            points += count;
        }
        cout << points << '\n';
    }
}