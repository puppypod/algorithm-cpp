#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N;

	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	// �� ������
	int left = 0;
	int right = N - 1;

	pair<int,int> answer;
	answer.first = v[left];
	answer.second = v[right];
	while (1) {
		// left ����
		if (v[left] + v[right] < 0) {
			left++;
		}
		// right ����
		else {
			right--;
		}
		if (left >= right) { break; }

		if (abs(answer.first + answer.second) >= abs(v[left] + v[right])) {
			answer.first = v[left];
			answer.second = v[right];
		}
	}
	cout << answer.first << " " << answer.second;
}