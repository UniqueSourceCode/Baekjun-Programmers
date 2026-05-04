#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int n = cookie.size();
    for (int m = 0; m < n-1; ++m) {
        int left = m;
        int right = m+1;
        int lsum = cookie[left];
        int rsum = cookie[right];
        
        while (left > -1 && right < n) {
            if (lsum < rsum) {
                left -= 1;
                if (left < 0) continue;
                lsum += cookie[left];
            } else if (lsum > rsum) {
                right += 1;
                if (right > n-1) continue;
                rsum += cookie[right];
            } else {
                if (lsum > answer) answer = lsum;
                left -= 1;
                if (left < 0) continue;
                lsum += cookie[left];
            }
        }
    }
    return answer;
}