#include <iostream>
using namespace std;

int N, M;
int nums[8];

void printNums(int index, int starting_num, int length) {
    if (length == 0) {
        for (int i = 0; i < M; ++i) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }
    //if N = 8 and length = 3, starting number can get up to 6 (6,7,8)
    int max_start = N - length + 1;
    for (int i = starting_num; i <= max_start; ++i) {
        nums[index] = i;
        printNums(index+1, i+1, length-1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    printNums(0, 1, M);
    return 0;
}