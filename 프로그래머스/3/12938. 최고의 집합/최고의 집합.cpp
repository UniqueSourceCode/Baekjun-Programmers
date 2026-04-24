#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s) {
        answer.push_back(-1);
        return answer;
    }
    int base = s/n;
    int base_count = n - (s - (base)*n);
    for (int i = 0; i < n; ++i) {
        if (base_count > 0) {
            answer.push_back(base);
            base_count--;
        } else {
            answer.push_back(base+1);
        }
    }
    return answer;
}