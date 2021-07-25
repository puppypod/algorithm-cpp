// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int>& A) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int num : A) {
        if (num > 0) {
            q.push(num);
        }
    }

    if (q.empty()) return 1;

    int prev = q.top();

    if (prev != 1) return 1;

    q.pop();

    while (!q.empty()) {
        int number = q.top();
        q.pop();
        if (prev + 1 >= number) {
            prev = number;
        }
        else {
            return prev + 1;
        }
    }
    return prev + 1;
}
