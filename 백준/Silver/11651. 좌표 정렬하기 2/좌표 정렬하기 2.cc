#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(2));
    while (n--) {
        cin >> arr[n][0] >> arr[n][1];
    }
    sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
        return (a[1] == b[1]) ?  a[0] < b[0] :  a[1] < b[1];
    });
    for (const auto& coords : arr) {
        cout << coords[0] << ' ' << coords[1] << "\n";
    }
    return 0;
}