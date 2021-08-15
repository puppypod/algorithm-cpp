#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
vector<int> dir[100001];
int order[100001];
int cnt = 1;
vector<pair<int, int>> answer;

int dfs(int id, int parent) {
	// 1. 방문 순서 기록 후 자식과 비교 준비
	
	order[id] = cnt;
	cnt++;

	int ret = order[id];

	// 2. 자식 DFS
	int len = dir[id].size();
	
	for (int i = 0; i < len; i++) {
		int now = dir[id][i];

		if (now == parent) continue;
		
		// 2-1. 자식 최초 방문했을 경우
		if (!order[now]) {
			// 자식 정점 중 방문순서가 빠른 값
			int low = dfs(now, id);
			// Root 가 아니고, order 역전이 불가능하면 단절점
			if (order[id] < low ) {
				if (now > id) {
					answer.push_back({ id,now });
				}
				else {
					answer.push_back({ now,id });
				}
			}
			ret = min(ret, low);
		}

		// 2-2. 자식을 이미 방문한 경우 --
		// 알고보니 조상님 low 였음. 즉, 끝 노드임
		else {
			ret = min(ret, order[now]);
		}
	}
	
	return ret;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		dir[a].push_back(b);
		dir[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		if (!order[i]) {
			dfs(i, 0);
		}
	}
	if (!answer.empty()) {
		sort(answer.begin(), answer.end());
	
		cout << answer.size() << '\n';
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i].first << " " << answer[i].second << '\n';
		}
	}
}