#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> hash;
    unordered_set<string> types;
    for (vector<string> v : clothes) {
        hash[v[1]]++;
        types.insert(v[1]);
    }
    for (string type : types) {
        answer *= hash[type]+1;
    }
    answer -= 1;
    return answer;
}