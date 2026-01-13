#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int k, n;
        cin >> k >> n;
        vector<int> arr(n, 1);
        for (int i = -1; i < k; ++i) {
            for (int j = 1; j < n; ++j) {
                arr[j] = arr[j-1] + arr[j];
            }
        }
        cout << arr[n-1] << '\n';
    }
    return 0;
}