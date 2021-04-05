#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> quiz[32001];
// 번호가 낮을 수록 우선순위를 부여해야하기 때문임
priority_queue<int, vector<int>, greater<int>> pq;
int map[32001] = { 0, };
int N, M;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		quiz[a].push_back(b);
		map[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (map[i] == 0) { // 우선순위가 가장 높은 것부터 push
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int num = pq.top();
		cout << num << " ";
		pq.pop();
		for (int delNum : quiz[num]) {
			map[delNum]--;
			if (map[delNum] == 0) {
				pq.push(delNum);
			}
		}
	}
	cout << endl;
}