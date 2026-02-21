#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    string num_to_pok[N+1];
    unordered_map<string, int> pok_to_num(N+1);
    for (int i = 1; i < N+1; ++i) {
        cin >> num_to_pok[i];
        pok_to_num[num_to_pok[i]] = i;
    }
    string problem;
    while (M--) {
        cin >> problem;
        if ('A' <= problem[0] && problem[0] <= 'z') {
            cout << pok_to_num[problem] <<'\n';
            continue;
        }
        cout << num_to_pok[std::stoi(problem)] << '\n';
    }
    return 0;
}