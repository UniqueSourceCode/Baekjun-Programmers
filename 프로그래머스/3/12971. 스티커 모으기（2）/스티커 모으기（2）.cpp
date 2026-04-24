#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    if (sticker.size() < 2) {
        if (sticker.size() == 1) answer = sticker[0];
        else answer = max(sticker[0], sticker[1]);
        return answer;
    }
    int prev0 = 0;
    int prev1 = 0;
    int new0 = prev1;
    int new1 = sticker[1];
    for (int i = 2; i < sticker.size(); ++i) {
        int x0 = max(prev1, new1);
        int x1 = max(prev0, new0) + sticker[i];
        prev0 = new0;
        prev1 = new1;
        new0 = x0;
        new1 = x1;
    }
    answer = max(new0, new1);
    
    prev0 = 0;
    prev1 = sticker[0];
    new0 = prev1;
    new1 = sticker[1];
    for (int i = 2; i < sticker.size(); ++i) {
        int x0 = max(prev1, new1);
        int x1 = max(prev0, new0) + sticker[i];
        prev0 = new0;
        prev1 = new1;
        new0 = x0;
        new1 = x1;
    }
    
    answer = max(answer, new0);
    
    return answer;
}