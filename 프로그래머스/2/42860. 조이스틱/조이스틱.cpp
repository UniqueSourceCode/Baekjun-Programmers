#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int window = 20;
    for (int i = 0; i < name.length(); ++i) {
        answer += ((name[i] - 'A') > 13) ? 26 - name[i] + 'A' : name[i] - 'A';
        int last_char_index = i + 1;
        while (last_char_index < name.length() && name[last_char_index] == 'A')
            last_char_index++;

        int right_first = 2*i + (name.length() - last_char_index);
        int left_first = 2*(name.length() - last_char_index) + i;
        window = min(window, min(right_first, left_first));
    }
    answer += window;
    return answer;
    }