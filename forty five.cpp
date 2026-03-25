#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    stack<int> s;

    // Input elements into queue
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Step 1: Move queue to stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Move stack back to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Print reversed queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}