#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> bag;
vector<pair<int, int>> thing;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first <= b.first) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		else {
			return true;
		}
	}
	else { return false; }
}
int main()
{
	int n, k;
	cin >> n >> k;
	int weight, cost;
	
	for (int i = 0; i < n; i++) {
		cin >> weight >> cost;
		thing.push_back({ weight,cost });
	}
	sort(thing.begin(), thing.end(), cmp);
	int bag_weight;
	for (int i = 0; i < k; i++) {
		cin >> bag_weight;
		bag.push_back(bag_weight);
	}
	sort(bag.begin(), bag.end());
	long long sum = 0;
	int idx = 0;

	priority_queue<int> pq;
	// 무게제한이 낮은 가방부터 최대한 비싼 보선을 넣는 방법
	for (int i = 0; i < k; i++) {
		// i번째 가방의 무게제한에 충족하는 보석을 모두 넣음
		while (idx < n && thing[idx].first <= bag[i]) {
			pq.push(thing[idx].second);
			idx++;
		}
		// pq 에는 무게에 충족하는 가장 값비싼 보석이 들어있음.
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum << endl;
}