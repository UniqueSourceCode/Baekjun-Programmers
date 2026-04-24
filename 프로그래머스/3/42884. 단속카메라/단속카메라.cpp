#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), [](auto& a, auto& b) {
       return a[1] < b[1]; 
    });
    int p = 0;
    int prev;
    while (p < routes.size()) {
        answer++;
        prev = routes[p][1];
        p++;
        if (p == routes.size()) break;
        while (routes[p][0] <= prev && prev <= routes[p][1]) {
            p++;
            if (p == routes.size()) break;
        }
    }
    return answer;
}