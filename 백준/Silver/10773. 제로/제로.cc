#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val = 0;
    Node* next = nullptr;
};

int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    while (n--) {
        int value;
        cin >> value;
        if (value == 0) {
            if (!head) continue;
            Node* tmp = head;
            head = head->next;
            delete tmp;
            continue;
        }
        Node* newNode = new Node{value, head};
        head = newNode;
    }
    int sum = 0;
    while (head) {
        sum += head->val;
        head = head->next;
    }
    cout << sum;
    return 0;
}