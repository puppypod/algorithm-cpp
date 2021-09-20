#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 500001;

vector<pair<int,int>> trees;
vector<int> input;
vector<int> inputCpy;
int s = 1;
int N;

void initBU() {
    // 외부 노드
    for (int i = 0; i < N; i++) {
        trees[s + i].first = inputCpy[i];
    }
    
    // 내부 노드는 초기화
    for (int i = s - 1; i >= 1; i--) {
        trees[i].first = min(trees[i * 2].first, trees[i * 2 + 1].first);
    }
}
int query(int left, int right, int node, int target, int sum) {
    trees[node].second += 1;
    // 종료 조건
    if (left == right) {
        return sum;
    }

    int mid = (left + right) / 2;
    // 만약 타겟이 우측 자식노드보다 작다면
    if (target < trees[node * 2 + 1].first) {
        return query(left, mid, node * 2, target, sum + trees[node * 2 + 1].second);
    }
    // 타겟이 우측 자식노드보다 크거나 같다면
    else {
        return query(mid + 1, right, node * 2 + 1, target, sum);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        input.push_back(a);
    }
    inputCpy = input;
    sort(inputCpy.begin(), inputCpy.end());
    
    while (s < N) s *= 2;

    trees.resize(s * 2, { 1000000001,0 });

    initBU();

    for (int i = 0; i < N; i++) {
        cout << query(1, s, 1, input[i], 0) + 1 << '\n';
    }
}