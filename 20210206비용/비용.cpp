#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000000;
int n, m;
vector<vector<int>> m_arr;
long long parents[100001]; // 최대 정점개수만큼 생성
long long vertex_num[100001];
long long weight_total = 0;
long long sum = 0;

bool cmp(vector<int> a, vector<int> b) {
	return a[2] > b[2];
}
int find(int idx) {
	if (idx == parents[idx]) {
		return idx;
	}
	return parents[idx] = find(parents[idx]);
}
void merge(int parent, int children) {
	parents[children] = parent;
	vertex_num[parent] += vertex_num[children];
	vertex_num[children] = 1;
}
int main()
{
	cin >> n >> m;
	int x, y, w;
	
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		m_arr.push_back({ x,y,w });
		weight_total += w;
	}
	// 초기 세팅
	for (int i = 1; i <= n; i++) { 
		parents[i] = i;
		vertex_num[i] = 1;
	}

	sort(m_arr.begin(), m_arr.end(), cmp); // 가중치 내림차순으로 정리
	int parent1, parent2, cost;
	for (int i = 0; i < m; i++) {
		parent1 = find(m_arr[i][0]);
		parent2 = find(m_arr[i][1]);
		cost = m_arr[i][2];
		if (parent1 != parent2) {
			sum += (((vertex_num[parent1] * vertex_num[parent2]) % MOD) * weight_total) % MOD;
			sum %= MOD;
			merge(parent1, parent2);
		}
		weight_total -= cost;
	}
	cout << sum << endl;
}