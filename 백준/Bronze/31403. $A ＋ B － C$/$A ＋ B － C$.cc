#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int N = B;
    int newA = A;
    while (N) {
        N = N/10;
        newA = newA * 10;
    }

    cout << (A+B-C) << '\n' << (newA+B-C);
    return 0;
}