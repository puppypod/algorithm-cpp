#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	if (N <= K) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	vector<int> diff(N - 1);

	for (int i = 0; i < N-1; i++) {
		diff[i] = v[i + 1] - v[i];
	}

	sort(diff.begin(), diff.end());

	int result = 0;
	for (int i = 0; i < N - K; i++) {
		result += diff[i];
	}
	cout << result << endl;
}