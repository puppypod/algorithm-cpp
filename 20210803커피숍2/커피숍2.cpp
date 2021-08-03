#include <iostream>
#include <vector>

using namespace std;

vector<long long> nums;
vector<long long> trees;
void initBU(int s) {
	// 리프 채우기
	for (int i = 0; i < nums.size(); i++) {
		trees[s + i] = nums[i];
	}

	// 내부 노드 채우기 (s-1 ~ 1), leftchild, rightchild
	for (int i = s - 1; i >= 1; i--) {
		int left = i * 2;
		int right = i * 2 + 1;
		trees[i] = trees[left] + trees[right];
	}
	return;
}
long long query(int left, int right, int node, int queryLeft, int queryRight) {
	// 연관이 없음 -> 결과에 영향이 없는 값 return 0;
	if ((right < queryLeft) || (left > queryRight)) return 0;
	
	// 판단 가능 -> 현재 노드 값 return 
	else if (left >= queryLeft && right <= queryRight) {
		return trees[node];
	}

	// 판단 불가, 자식에게 위임, 자식에서 올라온 합을 return
	else {
		int mid = (left + right) / 2;
		long long leftValue = query(left, mid, node * 2, queryLeft, queryRight);
		long long rightValue = query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
		return leftValue + rightValue;
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
	int N, Q;

	cin >> N >> Q;
	
	for (int i = 0; i < N; i++) {
		long long a; cin >> a;
		nums.push_back(a);
	}
	int s = 1;
	while (s < N) {
		s *= 2;
	}
	trees.resize(s * 2, 0);

	initBU(s);

	for (int i = 0; i < Q; i++) {
		int x, y;
		int a;
		long long b;
		cin >> x >> y >> a >> b;
		if (x > y) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		
		cout << query(1, s, 1, x, y) << '\n';

		long long diff = b - trees[s + a - 1];
		update(1, s, 1, a, diff);
	}
}