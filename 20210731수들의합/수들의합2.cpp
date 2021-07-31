#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	int left = 0;
	int right = 0;
	int answer = 0;
	while (1) {
		if (left == N || right == N) break;
		int sum = 0;
		for (int i = left; i <= right; i++) {
			sum += v[i];
		}
		if (sum == M) 
		{ 
			answer++; 
			left++;
		}
		else if (sum < M) right++;
		else if (sum > M) left++;
	}
	cout << answer;
}