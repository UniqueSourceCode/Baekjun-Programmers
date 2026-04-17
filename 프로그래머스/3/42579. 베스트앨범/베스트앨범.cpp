#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> freq;
    unordered_map<string, priority_queue<pair<int, int>>> top_plays;
    priority_queue<pair<int, string>> max_heap;
    
    for (int i = 0; i< genres.size(); ++i) {
        freq[genres[i]] += plays[i];
        top_plays[genres[i]].push({plays[i], i});
    }
    for (auto [key, value] : freq) {
        max_heap.push({value, key});
    }
    while (!max_heap.empty()) {
        auto [_, genre] = max_heap.top(); max_heap.pop();
        int i = 0;
        int freq = 0;
        while (i < 2 && !top_plays[genre].empty()) {
            auto [x, index] = top_plays[genre].top(); top_plays[genre].pop();
            
            if (freq == x && answer[answer.size()-1] > index) {
                int temp = answer[answer.size()-1];
                answer[answer.size()-1] = index;
                answer.push_back(temp);
            } else {
                answer.push_back(index);
            }
            
            freq = x;
            i++;
        }
    }
    
    return answer;
}