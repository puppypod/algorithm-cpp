#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	vector<pair<long long, long long>> jewelries;
	vector<int> bags;
	cin >> N >> K;
	// 각 보석의 정보
	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;
		jewelries.push_back({ m,v });
	}

	for (int i = 0; i < K; i++) {
		int c; cin >> c;
		bags.push_back(c);
	}
	sort(jewelries.begin(), jewelries.end());
	sort(bags.begin(), bags.end());

	priority_queue<pair<long long, long long>> pq;

	int p = 0;
	long long answer = 0;
	for (int i = 0; i < K; i++) {
		int bagWeight = bags[i];
		while (p < N) {
			long long m = jewelries[p].first;
			long long v = jewelries[p].second;

			if (m <= bagWeight) {
				pq.push({ v,m });
				p++;
			}
			else if (m > bagWeight) break;
		}
		if (!pq.empty()) {
			answer += pq.top().first;
			pq.pop();
		}
	}
	cout << answer << endl;
}