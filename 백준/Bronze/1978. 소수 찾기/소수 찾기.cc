#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, count = 0;
    int sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 2; j <= sqrt(arr[i]); ++j) {
            if (arr[i] % j == 0) {
                count++;
                break;
            }
        }
        if (count == 0 && arr[i] != 1) {
            sum++;
        }
        count = 0;
    }
    cout << sum;
    return 0;
}