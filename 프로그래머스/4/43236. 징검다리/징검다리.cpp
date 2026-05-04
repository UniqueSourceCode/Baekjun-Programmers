#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool removeRocks(int distance, int m, int n, vector<int>& rocks) {
    int curr = 0;
    int count = 0;
    for (auto& rock : rocks) {
        //remove rocks that violate current distance.
        if (rock - curr < m) {
            count++;
            continue;
        }
        curr = rock;
    }
    if (distance - curr < m) count++;
    return (count <= n);
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    int l = 0;
    int r = distance;
    while (l < r) {
        int m = l + (r-l)/2;
        if (removeRocks(distance, m, n, rocks)) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    if (removeRocks(distance, l, n, rocks)) {
        answer = l;
    } else {
        answer = l-1;
    }
    return answer;
}