#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcase;
	cin >> testcase;
	while (testcase--) {

		int n;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			pq.push(num);
		}
		long long sum = 0;
		while (pq.size() != 1) {
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();
			pq.push(a + b);
			sum = sum + a + b;
		}
		cout << sum << '\n';
	}
}