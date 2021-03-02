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
	// ���������� ���� ������� �ִ��� ��� ������ �ִ� ���
	for (int i = 0; i < k; i++) {
		// i��° ������ �������ѿ� �����ϴ� ������ ��� ����
		while (idx < n && thing[idx].first <= bag[i]) {
			pq.push(thing[idx].second);
			idx++;
		}
		// pq ���� ���Կ� �����ϴ� ���� ����� ������ �������.
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum << endl;
}