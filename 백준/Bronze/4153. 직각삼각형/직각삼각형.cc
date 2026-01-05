#include <iostream>
using namespace std;

int main() {
    long a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (!a && !b && !c) break;
        bool right = false;
        if ((c > a) && (c > b)) {
            if (a*a + b*b == c*c) right = true;
        } else if (a>b) {
            if (b*b + c*c == a*a) right = true;
        } else if (c*c + a*a == b*b) right = true;
        if (right) cout << "right" << endl;
        else cout << "wrong" << endl;
    }
    return 0;
}