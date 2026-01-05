#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    for (int i = M; i <= N; ++i) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i%j == 0)  {
                isPrime = false;
                break;
            }
        }
        if (isPrime && i != 1) cout << i << endl;
    }
    return 0;
}