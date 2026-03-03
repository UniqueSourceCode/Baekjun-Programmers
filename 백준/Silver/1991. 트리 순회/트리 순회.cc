#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    Node() : data('.'), left(nullptr), right(nullptr) {}
    char data;
    Node* left;
    Node* right;
};

void PreOrder(Node* root) {
    if (!root) return;
    cout << root->data;
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node* root) {
    if (!root) return;
    InOrder(root->left);
    cout << root->data;
    InOrder(root->right);
}

void PostOrder(Node* root) {
    if (!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    Node Nodes[26];
    for (int i = 0; i < N; ++i) {
        char A, B, C;
        cin >> A >> B >> C;
        int index = A - 'A';
        Nodes[index].data = A;
        if (B != '.') {
            Nodes[index].left = &Nodes[B - 'A'];
        }
        if (C != '.') {
            Nodes[index].right = &Nodes[C - 'A'];
        }
    }
    PreOrder(&Nodes[0]);
    cout << '\n';
    InOrder(&Nodes[0]);
    cout << '\n';
    PostOrder(&Nodes[0]);
    return 0;
}