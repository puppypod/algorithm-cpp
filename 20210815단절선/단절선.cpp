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
	// 1. �湮 ���� ��� �� �ڽİ� �� �غ�
	
	order[id] = cnt;
	cnt++;

	int ret = order[id];

	// 2. �ڽ� DFS
	int len = dir[id].size();
	
	for (int i = 0; i < len; i++) {
		int now = dir[id][i];

		if (now == parent) continue;
		
		// 2-1. �ڽ� ���� �湮���� ���
		if (!order[now]) {
			// �ڽ� ���� �� �湮������ ���� ��
			int low = dfs(now, id);
			// Root �� �ƴϰ�, order ������ �Ұ����ϸ� ������
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

		// 2-2. �ڽ��� �̹� �湮�� ��� --
		// �˰��� ����� low ����. ��, �� �����
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