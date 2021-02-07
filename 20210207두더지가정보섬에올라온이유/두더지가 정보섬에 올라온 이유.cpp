#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int parents[100001];
long long vertex_num[100001];
long long vertex_sum = 0;
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
	vertex_sum = vertex_num[parent] * vertex_num[children];
	vertex_num[parent] += vertex_num[children];
	vertex_num[children] = 1;
}
int main() 
{
	cin >> n;
	int x, y, w;
	vector<vector<int>> weight_arr;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y >> w;
		weight_arr.push_back({ x,y,w });
	}
	for (int i = 1; i <= n; i++) {
		parents[i] = i;
		vertex_num[i] = 1;
	}
	// 오름차순 정렬
	sort(weight_arr.begin(), weight_arr.end(),cmp);
	int parent1, parent2, cost;
	long long result = 0;
	
	for (int i = 0; i < n - 1; i++) {
		parent1 = find(weight_arr[i][0]);
		parent2 = find(weight_arr[i][1]);
		cost = weight_arr[i][2];

		if (parent1 != parent2) {
			merge(parent1, parent2);

			result += vertex_sum * cost;
		}
	}
	cout << result << endl;
}