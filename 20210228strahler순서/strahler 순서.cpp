#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vertex_out[1001];
vector<int> vertex_in[1001];
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int k, m, p;
		cin >> k >> m >> p;
		
		vector<int> dist;
		dist.resize(m + 1, 0);
		for (int j = 0; j < p; j++) {
			int a, b;
			cin >> a >> b;
			vertex_out[a].push_back(b);
			vertex_in[b].push_back(a);
		}

		queue<int> q;
		int ans = 0;
		for (int j = 1; j <= m; j++) {
			if (vertex_in[j].empty()) {
				q.push(j);
				dist[j] = 1;
			}
			if (vertex_out[j].empty()) {
				ans = j;
			}
		}
		while (!q.empty()) {
			int vertex = q.front();
			q.pop();
			for (int dest : vertex_out[vertex]) {
				bool isGo = true;
				if (dist[dest] == 0) {
					int mx_cnt = 0;
					int mx = -1;
					for (int src : vertex_in[dest]) {
						if (dist[src] == 0) { 
							isGo = false;
							break;
						}
						if (mx < dist[src]) { // 최댓값 갱신
							mx_cnt = 1;
							mx = dist[src];
						}
						else if(mx==dist[src]){ // 최댓값 개수 세기
							mx_cnt++;
						}
					}
					if (isGo) {
						if (mx_cnt == 1) {
							dist[dest] = mx;
						}
						else if(mx_cnt>=2){
							dist[dest] = mx + 1;
						}
						q.push(dest);
					}
					
				}
			}
		}
		for (int j = 0; j < 1000; j++) {
			vertex_in[j].clear();
			vertex_out[j].clear();
		}
		cout << k << " " << dist[ans] << endl;
	}
	
}