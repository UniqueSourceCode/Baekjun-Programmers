#include <string>
#include <vector>
using namespace std;
vector<vector<int>> cost = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,4,2,3,5,4,5,6,6,7,8},
    {0,2,1,2,3,2,3,5,4,5,7,6,7},
    {0,4,2,1,5,3,2,6,5,4,8,7,6},
    {0,2,3,5,1,2,4,2,3,5,4,5,6},
    {0,3,2,3,2,1,2,3,2,3,5,4,5},
    {0,5,3,2,4,2,1,5,3,2,6,5,4},
    {0,4,5,6,2,3,5,1,2,4,2,3,5},
    {0,5,4,5,3,2,3,2,1,2,3,2,3},
    {0,6,5,4,5,3,2,4,2,1,5,3,2},
    {0,6,7,8,4,5,6,2,3,5,1,2,4},
    {0,7,6,7,5,4,5,3,2,3,2,1,2},
    {0,8,7,6,6,5,4,5,3,2,4,2,1}
};
int solution(string numbers) {
    int answer = 1e9;
    vector<vector<int>> prev_dp(13, vector<int>(13, 1e9));
    vector<vector<int>> curr_dp(13, vector<int>(13, 1e9));
    
    prev_dp[4][6] = 0;
    
    for (int i = 0; i < numbers.size(); ++i) {
        int curr = numbers[i] - '0';
        if (numbers[i] == '*') {
            curr = 10;
        } else if (numbers[i] == '0') {
            curr = 11;
        } else if (numbers[i] == '#') {
            curr = 12;
        }
        
        for (auto& row : curr_dp) {
            fill(row.begin(), row.end(), 1e9);
        }
        for (int left = 1; left < 13; ++left) {
            for (int right = 1; right < 13; ++right) {
                if (curr != right)
                curr_dp[curr][right] = min(curr_dp[curr][right], prev_dp[left][right] + cost[left][curr]);
                
                if (curr != left)
                curr_dp[left][curr] = min(curr_dp[left][curr], prev_dp[left][right] + cost[right][curr]); 
            }
        }
        swap(curr_dp, prev_dp);
    }
    for (int i = 1; i< 13; ++i) {
        for (int j = 1; j < 13; ++j) {
            if (prev_dp[i][j] < answer) {
                answer = prev_dp[i][j];
            }
        }
    }
    return answer;
}