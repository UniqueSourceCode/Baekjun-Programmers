#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, num;
    string instructions;
    cin >> N;
    bool elements[21] = {0};
    while (N--) {
        cin >> instructions;
        if (instructions == "add") {
            cin >> num;
            elements[num] = true;
        } else if (instructions == "remove") {
            cin >> num;
            elements[num] = false;
        } else if (instructions == "check") {
            cin >> num;
            elements[num] ? cout << 1 << '\n': cout << 0 << '\n';
        } else if (instructions == "toggle") {
            cin >> num;
            elements[num] = !elements[num];
        } else if (instructions == "all") {
            for (int i = 1; i < 21; ++i) {
                elements[i] = true;
            }
        } else {
            for (int i = 1; i < 21; ++i) {
                elements[i] = false;
            }
        }

    }    
    return 0;
}