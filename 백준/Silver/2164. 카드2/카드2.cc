#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, i=0, answer;

    bool flag = false;
    cin >> N;
    int n = N;
    vector<bool> binary(n, true);
    while (n > 1) {
        if (i >= N) {
            i = 0;
        }
        if (binary[i]) {
            flag = !flag;
        }
        if (flag && binary[i]) {
            binary[i] = false;
            n--;
        }
        i++;
    }
    for (int j = 0; j < N; j++) {
        if (binary[j]) {
            answer = j+1;
        }
    }
    cout << answer;
}