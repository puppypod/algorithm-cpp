#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;


vector<int> v;
vector<int> number;
vector<int> position;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	number.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> number[i];
	}
	v.push_back(number[1]);
	position.push_back(0);

	for (int i = 2; i <= N; i++) {
		auto iter = lower_bound(v.begin(), v.end(), number[i]);

		// 삽입 위치 찾기
		int idx = iter - v.begin();

		if (iter == v.end()) {
			v.push_back(number[i]);
		}
		else {
			v[idx] = number[i];
		}

		position.push_back(idx);
	}

	int answer = v.size();
	deque<int> arr;
	int length = answer;

	cout << answer << '\n';
	for (int i = position.size() - 1; i >= 0; i--) {
		if (position[i] == length-1) {
			arr.push_front(number[i + 1]);
			length--;
		}
	}
	for (int ans : arr) {
		cout << ans << " ";
	}
	
}