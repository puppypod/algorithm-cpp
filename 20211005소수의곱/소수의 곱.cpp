#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

vector<long long> v;
set<long long> visited;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, K;
	cin >> K >> N;

	
	for (int i = 0; i < K; i++) {
		long long n; cin >> n;
		v.push_back(n);
	}

	long long maxValue = 0;
	pq.push(1);

	while (N) {
		long long number = pq.top();
		pq.pop();
		//cout << number << endl;

		for (int i = 0; i < K; i++) {
			long long newNum = number * v[i];

			// - 조건문 설명
			// pq가 꽉차있더라도 새롭게 들어갈 소수의 곱이 pq의 최댓값보다 작다면
			// pq에 넣어주어야 모든 경우의 조건을 만족할 수 있다.
			
			// 반대로 pq가 꽉 차있으며, 새롭게 들어갈 소수의 곱이 pq의 최댓값보다
			// 크다면, 더 이상 의미없는 값이 된다.
			if (pq.size() >= N && newNum > maxValue) break;

			if (visited.find(newNum) == visited.end()) {
				visited.insert(newNum);
				pq.push(newNum);
				maxValue = max(maxValue, newNum);
			}
		}

		N--;
	}
	
	cout << pq.top();
}