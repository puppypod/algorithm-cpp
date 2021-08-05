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
	// leaf에서 target을 찾음
	int node = s + target - 1;
	// value 반영
	trees[node] = value;
	// root에 도달할 때 까지 부모에 값 반영
	node /= 2;
	while (node > 0) {
		trees[node] = trees[node * 2] + trees[node * 2 + 1];
		node /= 2;
	}
}
long long queryBU(int queryLeft, int queryRight) {
	// leftNode 분기 조건
	/*짝수 : 부모의 값 사용, 홀수 : 현재 노드 값 추가*/
	// rightNode 분기 조건
	/*짝수 : 현재 노드 값 추가, 홀수 : 부모의 값 사용*/

	// leaf에서 left, right 설정
	int left = s + queryLeft - 1;
	int right = s + queryRight - 1;
	long long sum = 0;
	while (left <= right) {
		// 좌측 노드가 홀수이면 현재 노드 값 사용하고 한칸 옆으로
		if (left % 2 == 1) {
			sum += trees[left]; left++;
		}

		// 우측 노드가 짝수이면 현재 노드 값 사용하고 한칸 옆으로
		if (right % 2 == 0) {
			sum += trees[right]; right--;
		}

		// 좌측, 우측 모두 부모로 이동
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