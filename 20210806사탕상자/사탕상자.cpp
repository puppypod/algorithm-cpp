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

	// ������ Ž���ؾ��ϴ� ���
	if (result == 0 && trees[leftc] >= priorityNum) {
		result = query(left, mid, leftc, priorityNum);
		return result;
	}

	// ������ ��� �������� �˻��ϸ� ��.
	if (result == 0 && trees[rightc] >= priorityNum) {
		result = query(mid + 1, right, rightc, priorityNum - trees[leftc]);
		return result;
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
	int n;
	cin >> n;

	while (s < 1000000) s *= 2;

	
	
	// �ִ� �ܺ� ����� ���� �ʱ�ȭ, ���׸�Ʈ Ʈ��
	trees.resize(s*2, 0);

	for (int i = 0; i < n; i++) {
		int a, b;
		long long c;
		cin >> a;
		// ������ ���� �� ��� ���, ������ ���� pop()
		if (a == 1) {
			// ���� ������ ���� -> query
			cin >> b;

			// b��° �켱���� ���� ���ϱ�
			int idx = query(1, s, 1, b);
			result = 0;
			// number--
			update(1, s, 1, idx, -1);
		}
		// ������ ���� �� ���� �ʴ� ��� 
		else {
			cin >> b >> c;
			update(1, s, 1, b, c);
		}
	}
	
}