#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int>& A) {
    priority_queue<int> q;
    for (int num : A) {
        q.push(num);
    }
    int number = q.top();
    q.pop();
    while (!q.empty()) {
        int cmpNum = q.top();
        q.pop();
        if (number == cmpNum) {
            number = q.top();
            q.pop();
        }
        else return number;
    }
    return number;
}