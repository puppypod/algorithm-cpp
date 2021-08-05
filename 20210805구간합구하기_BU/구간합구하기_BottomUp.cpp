#include <iostream>
#include <vector>

using namespace std;

int s = 1;
vector<long long> nums;
vector<long long> trees;

// Bottom-Up

void initBU() {
	for (int i = 0; i < nums.size(); i++) {
		trees[s + i] = nums[i];
	}

	for (int i = s - 1; i >= 1; i--) {
		trees[i] = trees[i * 2] + trees[i * 2 + 1];
	}
}
void updateBU(int target, long long value) {
	// leaf���� target�� ã��
	int node = s + target - 1;
	// value �ݿ�
	trees[node] = value;
	// root�� ������ �� ���� �θ� �� �ݿ�
	node /= 2;
	while (node > 0) {
		trees[node] = trees[node * 2] + trees[node * 2 + 1];
		node /= 2;
	}
}
long long queryBU(int queryLeft, int queryRight) {
	// leftNode �б� ����
	/*¦�� : �θ��� �� ���, Ȧ�� : ���� ��� �� �߰�*/
	// rightNode �б� ����
	/*¦�� : ���� ��� �� �߰�, Ȧ�� : �θ��� �� ���*/

	// leaf���� left, right ����
	int left = s + queryLeft - 1;
	int right = s + queryRight - 1;
	long long sum = 0;
	while (left <= right) {
		// ���� ��尡 Ȧ���̸� ���� ��� �� ����ϰ� ��ĭ ������
		if (left % 2 == 1) {
			sum += trees[left]; left++;
		}

		// ���� ��尡 ¦���̸� ���� ��� �� ����ϰ� ��ĭ ������
		if (right % 2 == 0) {
			sum += trees[right]; right--;
		}

		// ����, ���� ��� �θ�� �̵�
		left /= 2;
		right /= 2;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		nums.push_back(a);
	}

	while (s < N) { s *= 2; }

	trees.resize(s * 2, 0);
	initBU();

	for (int i = 0; i < M + K; i++) {
		int a;
		cin >> a;
		if (a == 1) { // updateBU
			int b; long long number;
			cin >> b >> number;
			updateBU(b, number);
		}
		else if (a == 2) { // queryBU
			int b, c;
			cin >> b >> c;
			cout << queryBU(b, c) << '\n';
		}
	}
}