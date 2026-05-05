#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int DFS(vector<vector<int>>& matches, int idx, int mask, unordered_set<int>& hash) {
    if (idx == matches.size()) {
        hash.insert(mask);
        return -1;
    }
    
    for (auto& next : matches[idx]) {
        if (mask & (1 << next)) continue;
        DFS(matches, idx+1, mask | (1 << next), hash);
    }
    
    return hash.size();
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int>> matches(banned_id.size());
    for (int i = 0; i < banned_id.size(); ++i) {
        string curr = banned_id[i];
        for (int j = 0; j < user_id.size(); ++j) {
            string curr_id = user_id[j];
            bool found = true;
            for (int k = 0; k < curr.size(); ++k) {
                if (curr.size() != curr_id.size()) {
                    found = false;
                    break;
                }
                
                if (curr[k] == '*') continue;
                if (curr[k] != curr_id[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                matches[i].push_back(j);
            }
        }
    }
    
    unordered_set<int> hash;
    int mask = 0;
    answer = DFS(matches, 0, 0, hash);
    return answer;
}