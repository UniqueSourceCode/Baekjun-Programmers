#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int count = 0;
    int front_batch = 0;
    int back_batch = 0;
    int N;
    cin >> N;
    int curr = 0;
    int prev = 0;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (curr == num) {
            back_batch++;
        } else if (prev == num) {
            front_batch += back_batch;
            back_batch = 1;
            prev = curr;
            curr = num;
        } else {
            front_batch = back_batch;
            back_batch = 1;
            prev = curr;
            curr = num;
        }

        if (count < front_batch + back_batch) count = front_batch + back_batch;
    }
    cout << count;
    return 0;
}