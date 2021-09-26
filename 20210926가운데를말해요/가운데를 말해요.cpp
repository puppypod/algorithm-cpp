#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> input;
vector<int> inputCpy;
// first->기준값, second->존재유무
vector<pair<int,int>> trees;
int N;
int s = 1;

void initBU() {
    for (int i = 0; i < N; i++) {
        trees[s + i].first = input[i];
    }

    for (int i = s - 1; i >= 1; i--) {
        trees[i].first = min(trees[i * 2].first, trees[i * 2 + 1].first);
    }
}
int query(int left, int right, int node, int findMid) {
    int mid = (left + right) / 2;
    // 1. 말단 노드에 도착했다면
    if (left == right) {
        // 중간 값
        return trees[node].first;
    }

    // 2. 왼쪽 자식 노드의 값이 findMid보다 크다면
    if (trees[node * 2].second >= findMid) {
        return query(left, mid, node * 2, findMid);
    }
    // 3. 그 외의 경우
    else {
        return query(mid + 1, right, node * 2 + 1, findMid - trees[node * 2].second);
    }

}
void update(int left, int right, int node, int target) {
    trees[node].second += 1;
    int mid = (left + right) / 2;
    
    // 3. 종료 조건
    if (left == right) {
        return;
    }

    // 1. 왼쪽 자식으로 가는 경우
    if (target < trees[node*2+1].first) {
        update(left, mid, node * 2, target);
    }

    // 2. 오른쪽 자식으로 가는 경우
    else {
        update(mid+1, right, node * 2 + 1, target);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    set<int> set1;

    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        inputCpy.push_back(n);
        if (set1.find(n) == set1.end()) {
            set1.insert(n);
            input.push_back(n);
        }
    }
    N = set1.size();

    sort(input.begin(), input.end());

    while (s < N) s *= 2;
    trees.resize(s * 2, { 10001,0 });
    initBU();

    for (int i = 0; i < inputCpy.size(); i++) {
        int num = inputCpy[i];
        update(1, s, 1, num);
        int findMid = (i + 1 + 1) / 2;

        cout << query(1, s, 1, findMid) << '\n';
    }
}