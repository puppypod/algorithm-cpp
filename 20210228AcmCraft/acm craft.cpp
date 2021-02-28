#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> vertex_arrow[1001];
		vector<int> dist;
		vector<int> v_in;
		v_in.resize(n + 1, 0);
		dist.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			dist[i] = tmp;
		}
		
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			
			v_in[b]++;
			vertex_arrow[a].push_back(b);
		}
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (v_in[i] == 0) {
				q.push(i);
			}
		}
		int ans;
		cin >> ans;

		vector<int> v_in_max(n + 1, 0);
		while (!q.empty()) {
			int src = q.front();
			q.pop();
			for (int dest : vertex_arrow[src]) {
				v_in[dest]--;
				if (v_in_max[dest] < dist[src]) {
					v_in_max[dest] = dist[src]; // 해당 건물을 짓기위한 최대 시간
				}
				if (v_in[dest] == 0) {
					dist[dest] += v_in_max[dest];
					q.push(dest);
				}
			}
		}
		
		cout <<dist[ans] << endl;
	}
}