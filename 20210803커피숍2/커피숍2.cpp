#include <iostream>
#include <vector>

using namespace std;

vector<long long> nums;
vector<long long> trees;
void initBU(int s) {
	// ���� ä���
	for (int i = 0; i < nums.size(); i++) {
		trees[s + i] = nums[i];
	}

	// ���� ��� ä��� (s-1 ~ 1), leftchild, rightchild
	for (int i = s - 1; i >= 1; i--) {
		int left = i * 2;
		int right = i * 2 + 1;
		trees[i] = trees[left] + trees[right];
	}
	return;
}
long long query(int left, int right, int node, int queryLeft, int queryRight) {
	// ������ ���� -> ����� ������ ���� �� return 0;
	if ((right < queryLeft) || (left > queryRight)) return 0;
	
	// �Ǵ� ���� -> ���� ��� �� return 
	else if (left >= queryLeft && right <= queryRight) {
		return trees[node];
	}

	// �Ǵ� �Ұ�, �ڽĿ��� ����, �ڽĿ��� �ö�� ���� return
	else {
		int mid = (left + right) / 2;
		long long leftValue = query(left, mid, node * 2, queryLeft, queryRight);
		long long rightValue = query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
		return leftValue + rightValue;
	}
}
void update(int left, int right, int node, int target, long long diff) {
	// ���� ����
	if (target < left || target > right) return;
	
	// ���� ���� -> ���� ��忡 diff �ݿ� -> �ڽĿ��� diff����
	else {
		trees[node] += diff;
		if (left == right) {
			return;
		}
		int mid = (left + right) / 2;
		// ���� Ȯ��
		update(left, mid, node * 2, target, diff);

		// ������ Ȯ��
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