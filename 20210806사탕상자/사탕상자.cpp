#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> trees;
long long result = 0;
int s = 1;

long long query(int left, int right, int node, int priorityNum) {
	if ((left == right) && !result) {
		cout << left << '\n';
		return left;
	}

	int leftc = node * 2;
	int rightc = node * 2 + 1;
	int mid = (left + right) / 2;

	// 왼쪽을 탐색해야하는 경우
	if (result == 0 && trees[leftc] >= priorityNum) {
		result = query(left, mid, leftc, priorityNum);
		return result;
	}

	// 나머지 경우 오른쪽을 검색하면 됨.
	if (result == 0 && trees[rightc] >= priorityNum) {
		result = query(mid + 1, right, rightc, priorityNum - trees[leftc]);
		return result;
	}
}
void update(int left, int right, int node, int target, long long diff) {
	// 연관 없음
	if (target < left || target > right) return;

	// 연관 있음 -> 현재 노드에 diff 반영 -> 자식에게 diff전달
	else {
		trees[node] += diff;
		if (left == right) {
			return;
		}
		int mid = (left + right) / 2;
		// 왼쪽 확인
		update(left, mid, node * 2, target, diff);

		// 오른쪽 확인
		update(mid + 1, right, node * 2 + 1, target, diff);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	while (s < 1000000) s *= 2;

	
	
	// 최대 외부 노드의 개수 초기화, 세그먼트 트리
	trees.resize(s*2, 0);

	for (int i = 0; i < n; i++) {
		int a, b;
		long long c;
		cin >> a;
		// 동생이 말을 잘 듣는 경우, 사탕을 꺼냄 pop()
		if (a == 1) {
			// 꺼낼 사탕의 순위 -> query
			cin >> b;

			// b번째 우선순위 사탕 구하기
			int idx = query(1, s, 1, b);
			result = 0;
			// number--
			update(1, s, 1, idx, -1);
		}
		// 동생이 말을 잘 듣지 않는 경우 
		else {
			cin >> b >> c;
			update(1, s, 1, b, c);
		}
	}
	
}