#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// first -> value, second -> idx
deque<int> v;
deque<int> vIdx;
int N, L;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> L;
    vIdx.resize(N);
    for (int i = 1; i <= N; i++) {
        int number; cin >> number;
        auto iter = lower_bound(v.begin(), v.end(), number);
        int idx = iter - v.begin();
        if (iter==v.end()) {
            v.push_back(number);
            vIdx[idx] = i;
        }
        else {
            v[idx] = number;
            vIdx[idx] = i;
        }

        // 1. 범위 내에 해당하지 않는 경우
        while (vIdx[0] < i - L + 1) {
            v.pop_front();
            vIdx.pop_front();
        }
        
        // 2. 필터링 후에 출력
        cout << v[0] << " ";
    }
}