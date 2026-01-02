#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> queue;
    while (N--) {
        string command;
        cin >> command;
        if (command == "push") {
            int value;
            cin >> value;
            queue.push_back(value);
        } else if (command == "pop") {
            if (queue.empty()) {
                cout << -1 << endl;
            } else {
                cout << queue.front() << endl;
                queue.erase(queue.begin());
            }
        } else if (command == "size") {
            cout << queue.size() << endl;
        } else if (command == "empty") {
            cout << (queue.empty() ? 1 : 0) << endl;
        } else if (command == "front") {
            if (queue.empty()) {
                cout << -1 << endl;
            } else {
                cout << queue.front() << endl;
            }
        } else if (command == "back") {
            if (queue.empty()) {
                cout << -1 << endl;
            } else {
                cout << queue.back() << endl;
            }
        }
    }


}