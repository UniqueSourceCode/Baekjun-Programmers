#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > pq;
    
    sort(jobs.begin(), jobs.end());
    int total = 0;
    int curr_time = 0;
    int i = 0;
    while (i < jobs.size() || !pq.empty()) {
        while (i < jobs.size() && jobs[i][0] <= curr_time) {
            pq.push({jobs[i][1], jobs[i][0], i});
            i++;
        }
        
        if (!pq.empty()) {
            auto [len, start, idx] = pq.top(); pq.pop();
            curr_time += len;
            total += curr_time - start;
        } else {
            curr_time++;
        }
    }
    answer = total/jobs.size();
    return answer;
}