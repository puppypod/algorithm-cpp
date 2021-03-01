#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> map;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		map.push_back(a);
	}
	sort(map.begin(), map.end());
	
	
	if (map[0] != 1) {
		cout << 1 << endl;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += map[i];
		if (i == n - 1) { break; }
		if (sum - map[i + 1] < -1) { // ºÒ°¡´É
			break;
		}
	}
	cout << sum + 1 << endl;
}