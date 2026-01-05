#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int room = 1;
    int upper = 1;
    while (true) {
        if (n <= upper) break;
        upper += 6*room++;
    }
    cout << room;
    return 0;
}