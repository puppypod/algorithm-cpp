#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, C;
	cin >> N >> C;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	int mn = 1;
	int mx = v[N - 1]- v[0];
	int answer = -1;

	while (mn <= mx) {
		int mid = (mn + mx) / 2;

		int left = 0;
		int right = 1;
		int cnt = 1;

		int tmp = 1000000001;
		// mid �Ÿ� ���� ��ŭ�̶� �������� �� ��ġ ������ ������ �������ϱ�
		while (left != N - 1 && right != N) {
			if (v[right] - v[left] >= mid) {
				// �ּڰ� ���ϱ�
				tmp = min(v[right] - v[left], tmp);
				cnt++;
				left = right;
				right++;
			}
			else {
				right++;
			}
		}
		// ������ ���� ����� ��, ���� ������
		if (cnt >= C) {
			answer = max(tmp, answer);
			mn = mid + 1;
		}
		// ������ ���� ������� ���� ��, ���� ������
		else {
			mx = mid - 1;
		}
	}
	cout << answer;
}