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
	// 1. �湮 ���� ��� �� �ڽİ� �� �غ�
	order[id] = cnt;
	cnt++;

	int child = 0;
	int ret = order[id];

	// 2. �ڽ� DFS
	int len = dir[id].size();
	
	for (int i = 0; i < len; i++) {
		int now = dir[id][i];
		if (now == parent) continue;

		// 2-1. �ڽ� ���� �湮���� ���
		if (!order[now]) {
			child++;
			// �ڽ� ���� �� �湮������ ���� ��
			int low = dfs(now, false, id);
			// Root �� �ƴϰ�, order ������ �Ұ����ϸ� ������
			if (!isRoot && order[id] <= low) {
				isDjj[id] = true;
			}
			ret = min(ret, low);
		}

		// 2-2. �ڽ��� �̹� �湮�� ��� --
		// �˰��� ����� low ����. ��, �� �����
		else {
			ret = min(ret, order[now]);
		}
	}
	// 3. ��Ʈ ������ ��� �ڽ� ������ 2�� �̻��̸� ������
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