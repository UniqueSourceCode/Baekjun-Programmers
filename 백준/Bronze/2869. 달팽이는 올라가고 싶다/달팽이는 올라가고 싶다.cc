#include <iostream>
using namespace std;

int main() {
    long n, m, v;
    cin >> n >> m >> v;
    long ans;
    (v-n)%(n-m) ? ans = (v-n)/(n-m) + 2 : ans = (v-n)/(n-m) + 1;
    cout << ans;
    return 0;
}