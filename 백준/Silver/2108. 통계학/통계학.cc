#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        v[i] = x;
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int x : v) sum += x;

    int avg;
    avg = round((double)sum/N);

    int median = v[N/2];

    map<int, int> frequency;
    for (int x : v) frequency[x]++;
    int mode = 0;
    int maxCount = 0;
    int index = 0;
    for (auto [num, count] : frequency) {
        if (count > maxCount) {
            maxCount = count;
            mode = num;
            index = 0;
        }
        if (count == maxCount) {
            ++index;
            if (index == 2) {
                mode = num;
            }
        }
    }

    int range = v[N-1] - v[0];
    
    cout << avg << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';
    return 0;
}