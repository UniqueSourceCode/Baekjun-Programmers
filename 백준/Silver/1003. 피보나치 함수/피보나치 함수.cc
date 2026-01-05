#include <iostream>
using namespace std;

int main() {
    int zeros[41] = {0};
    int ones[41] = {0};
    int finished_index = 2;
    int n;
    cin >> n;
    zeros[0] = 1;
    zeros[1] = 0;
    ones[0] = 0;
    ones[1] = 1;
    while (n--) {
        int N;
        cin >> N;
        while (finished_index <= N) {
            zeros[finished_index] = zeros[finished_index-1] + zeros[finished_index-2];
            ones[finished_index] = ones[finished_index-1] + ones[finished_index-2];
            finished_index++;
        }
        cout << zeros[N] << " " << ones[N] << "\n";
    }
    return 0;
}