#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> quiz[32001];
// ��ȣ�� ���� ���� �켱������ �ο��ؾ��ϱ� ������
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
		if (map[i] == 0) { // �켱������ ���� ���� �ͺ��� push
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