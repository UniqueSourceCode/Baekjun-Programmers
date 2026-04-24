#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    //first apt with no signal
    int p = 1;
    for (int& x : stations) {
        int unreached = (x-w) - p;
        if (unreached > 0) {
            answer += (unreached-1)/(2*w + 1)+1;
        }
        p = x+w+1;
    }
    
    if (p <= n) {
        answer += (n-p)/(2*w + 1)+1;
    }
    
    return answer;
}