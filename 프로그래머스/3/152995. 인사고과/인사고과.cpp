#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 0;
    int scoreA = scores[0][0];
    int scoreB = scores[0][1];
    int rank = 1;
    sort(scores.begin(), scores.end(), [](auto& a, auto& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });
    
    int curr_max = 0;
    for (int i = 0; i < scores.size(); ++i) {
        if (scores[i][0] == scoreA && scores[i][1] == scoreB) {
            if (scoreB < curr_max) return -1;
        }
        if (scores[i][1] < curr_max) continue;
        
        curr_max = scores[i][1];
        if (scores[i][0] + scores[i][1] > scoreA + scoreB) rank++;
    }
    answer = rank;
    return answer;
}