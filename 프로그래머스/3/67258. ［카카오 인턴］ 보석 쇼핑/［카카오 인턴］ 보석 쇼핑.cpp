#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_set<string> gemset(gems.begin(), gems.end());
    int n = gemset.size();
    
    unordered_map<string, int> hash;
    
    int length = 1e9;
    int l = 0;
    int r = 0;
    hash[gems[0]]++;
    int count = 1;
    
    while (r < gems.size() && l < gems.size()) {
        if (count < n) {
            r++;
            if (r > gems.size()-1) continue;
            if (++hash[gems[r]] == 1) {
                count++;
            }
        } else {
            if (l > gems.size()-1) continue;
            if (--hash[gems[l]] == 0) {
                count--;
                if (r-l < length) {
                    length = r-l;
                    answer = {l+1, r+1};
                }
            }
            l++;
        }
    }
    return answer;
}