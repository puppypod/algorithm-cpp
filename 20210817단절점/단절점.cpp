#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
vector<int> dir[10001];
int order[10001];
int cnt = 1;
bool isDjj[10001];
int answer = 0;

int dfs(int id, bool isRoot, int parent) {
	// 1. 방문 순서 기록 후 자식과 비교 준비
	order[id] = cnt;
	cnt++;

	int child = 0;
	int ret = order[id];

	// 2. 자식 DFS
	int len = dir[id].size();
	
	for (int i = 0; i < len; i++) {
		int now = dir[id][i];
		if (now == parent) continue;

		// 2-1. 자식 최초 방문했을 경우
		if (!order[now]) {
			child++;
			// 자식 정점 중 방문순서가 빠른 값
			int low = dfs(now, false, id);
			// Root 가 아니고, order 역전이 불가능하면 단절점
			if (!isRoot && order[id] <= low) {
				isDjj[id] = true;
			}
			ret = min(ret, low);
		}

		// 2-2. 자식을 이미 방문한 경우 --
		// 알고보니 조상님 low 였음. 즉, 끝 노드임
		else {
			ret = min(ret, order[now]);
		}
	}
	// 3. 루트 정점인 경우 자식 개수가 2개 이상이면 단절점
	if (isRoot && child >= 2) {
		isDjj[id] = true;
	}
	return ret;
}
int main()
{
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		dir[a].push_back(b);
		dir[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		if (!order[i]) {
			dfs(i, true, 0);
		}
	}
	vector<int> ans;
	for (int i = 1; i <= V; i++) {
		if (isDjj[i]) {
			ans.push_back(i);
			answer++;
		}
	}
	cout << answer << '\n';
	for (int a : ans) {
		cout << a << " ";
	}
}