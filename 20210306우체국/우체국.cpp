#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<long long>> v;

int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	for (long long i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		sum += b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	long long left = 0;
	long long right = sum / 2;
	int answer = 0;
	while (left <= right) {
		left += v[answer][1];
		answer++;
	}
	cout << v[answer - 1][0] << endl;
	
}