#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    while (true) {
        if (n <= 0) break;
        if (n%5 == 0) {
            count += n/5;
            n = 0;
            break;
        }
        n -= 3;
        count++;
    }
    (n == 0) ? cout << count : cout << -1;
    return 0;
}