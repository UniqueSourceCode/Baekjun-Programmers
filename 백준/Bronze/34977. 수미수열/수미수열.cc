#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    bool sumi;
    vector<int> numbers;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    for (int i = 1; i <=N/2; ++i) {
        for (int j = 0; j < i; ++j) {
            if (numbers[j] != numbers[N-i+j]) {
                sumi = false;
                break;
            } else {
                sumi = true;
            }
        }
        if (sumi) break;
    }
    sumi ? cout << "yes" : cout << "no";
    return 0;
}