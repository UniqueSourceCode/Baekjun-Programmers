#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    int prev0, prev1, pprev0, pprev1;
    
    pprev0 = 0;
    pprev1 = 0;
    prev0 = pprev1;
    prev1 = money[1];
    for (int i = 2; i < n; ++i) {
        int new0 = max(pprev1, prev1);
        int new1 = max(pprev0, prev0) + money[i];
        pprev0 = prev0;
        pprev1 = prev1;
        prev0 = new0;
        prev1 = new1;
    }

    answer = max(prev0, prev1);

    pprev0 = 0;
    pprev1 = money[0];
    prev0 = pprev1;
    prev1 = money[1];
    for (int i = 2; i < n; ++i) {
        int new0 = max(pprev1, prev1);
        int new1 = max(pprev0, prev0) + money[i];
        pprev0 = prev0;
        pprev1 = prev1;
        prev0 = new0;
        prev1 = new1;
    }
    
    answer = max(answer, prev0);
    return answer;
}