#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long foo(int left_rem, int right_rem, int count) {
    if (count < 0) return 0;
    if (left_rem < 0 || right_rem < 0) return 0;
    if (left_rem == 0 && right_rem == 0) return 1;
    int x = 0;
    x += foo(left_rem-1, right_rem, count+1);
    x += foo(left_rem, right_rem-1, count-1);
    return x;
}

int solution(int n) {
    int answer = foo(n, n, 0);
    return answer;
}