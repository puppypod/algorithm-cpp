#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int a, b;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while (1) {
        a = pq.top(); pq.pop();

        if (a >= K) { break; }
        if (pq.empty() && a < K) { answer = -1; break; }
        b = pq.top() * 2; pq.pop();
        answer++;
        pq.push(a + b);
    }
    
    return answer;
}
int main()
{
    vector<int> v = { 1, 2, 3, 9, 10, 12 };
    cout << solution(v, 106);
}