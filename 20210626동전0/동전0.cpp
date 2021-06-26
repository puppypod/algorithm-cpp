#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N, K;

void combination() {
	
}
int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		if (num > K)continue;
		v.push_back(num);
	}
	int sum = 0;
	int answer = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		int value = v[i];
		
		if (K / value == 0) continue;
		int n = K / value;
		answer += n;
		K = K - value * n;
		if (K == 0)break;
	}
	cout << answer;
}