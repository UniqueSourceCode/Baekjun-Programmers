#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<int> dp(500, 0);
    for (vector<int> line : triangle) {
        line[0] = dp[0] + line[0];
        for (int i = 1; i < line.size(); ++i) {
            line[i] = max(line[i]+dp[i-1], line[i]+dp[i]);
        }
        dp = line;
    }
    for (int num : dp) {
        if (num > answer) answer = num;
    }
    return answer;
}