#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    if (numbers.empty()) {
        return (target == 0) ? 1 : 0;
    }
    int answer = 0;
    int curr = numbers[0];
    
    numbers.erase(numbers.begin());
    answer += solution(numbers, target-curr);
    answer += solution(numbers, target+curr);
    return answer;
}