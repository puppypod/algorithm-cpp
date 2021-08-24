#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		v[i] = v[i - 1] + num;
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int total = v[b];
		int result = total - v[a - 1];
		cout << result << '\n';
	}
}