#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	if (N <= 2) {
		if (N == 1) {
			cout << 0 << '\n';
		}
		else {
			while (!pq.empty()) {
				sum += pq.top();
				pq.pop();
			}
			cout << sum << '\n';
		}
		return 0;
	}

	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		pq.push(a + b);
		sum = sum + a + b;
	}
	cout << sum << '\n';
}