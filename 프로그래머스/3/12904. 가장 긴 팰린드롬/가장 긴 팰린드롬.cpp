#include <iostream>
#include <string>
using namespace std;
int solution(string s) {
    int answer=0;
    
    for (int i = 0; i < s.size(); ++i) {
        int odd = 1;
        bool odd_active = true;
        int even = 0;
        bool even_active = true;
        for (int j = 1; j < s.size(); ++j) {
            if (i-j < 0 || i+j-1 >= s.size()) even_active = false;
            if (i-j < 0 || i+j >= s.size()) odd_active = false;
            if (even_active && s[i-j] == s[i+j-1]) {
                even += 2;
            } else {
                even_active = false;
            }
            
            if (odd_active && s[i-j] == s[i+j]) {
                odd += 2;
            } else {
                odd_active = false;
            }
            
            if (!even_active && !odd_active) break;
        }
        if (odd > answer) answer = odd;
        if (even > answer) answer = even;
    }

    return answer;
}