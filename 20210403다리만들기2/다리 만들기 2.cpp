#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100000000
int N, M;
vector<vector<int>> map;
vector<vector<int>> visit;
vector<vector<int>> bridgeMap;
vector<vector<int>> tmp_map;
vector<int> bridgevisit;
vector<vector<int>> candidate;
vector<vector<int>> tmp;
int answer = MAX;
int pick;

int dir[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };
int cnt = 1;

// ��� ���� ����ƴ��� Ȯ��
bool isAllConnect() {
	return true;
}
bool isTrue(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}
// �� ��ȣ �ű��
void dfs(int r, int c) {
	visit[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int dx = r + dir[i][0];
		int dy = c + dir[i][1];
		if (isTrue(dx, dy) && !visit[dx][dy] && map[dx][dy]) {
			map[dx][dy] = cnt;
			dfs(dx, dy);
		}
	}
}
// �ٸ��� �ּڰ� ���ϱ�
void checkBridge(int r, int c, int num) {
	for (int i = 0; i < 4; i++) {
		int dx = r + dir[i][0];
		int dy = c + dir[i][1];
		int bridgeLength = 0;
		while (isTrue(dx, dy) && map[dx][dy] == 0) {
			
			// �ٸ�����
			bridgeLength++;
			dx += dir[i][0];
			dy += dir[i][1];
			if (!isTrue(dx, dy)) { break; }
			if (map[dx][dy]) {
				if (bridgeLength == 1) { break; }
				if (num == map[dx][dy]) { break; }
				bridgeLength = min(bridgeLength, bridgeMap[num][map[dx][dy]]);
				bridgeMap[num][map[dx][dy]] = bridgeLength;
				break;
			}
		}
		
	}
}
// �湮�� �ٸ��� Check
void checkPossible(int v) {
	bridgevisit[v] = 1;
	for (int i = 1; i < cnt; i++) {
		if (!bridgevisit[i] && tmp_map[v][i]) {
			checkPossible(i);
		}
	}
}
// ����
void combinationBridge(int a, int b) {
	if (b == pick) {
		vector<vector<int>> init_map(cnt, vector<int>(cnt, 0));
		tmp_map = init_map;
		vector<int> init(cnt, 0);
		bridgevisit = init;
		int sum = 0;
		for (int i = 0; i < pick; i++) {
			sum += tmp[i][2];
			tmp_map[tmp[i][0]][tmp[i][1]] = 1;
			tmp_map[tmp[i][1]][tmp[i][0]] = 1;
		}
		checkPossible(tmp[0][0]);
		for (int i = 1; i < bridgevisit.size(); i++) {
			if (!bridgevisit[i]) {
				return;
			}
		}
		
		answer = min(answer, sum);

		return;
	}


	for (int i = a; i < candidate.size(); i++) {
		tmp[b] = candidate[i];
		combinationBridge(i + 1, b + 1);
	}
}
int main()
{
	cin >> N >> M;
	map.resize(N, vector<int>(M));
	visit.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	// �� ���� �����ϱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && map[i][j]) {
				map[i][j] = cnt;
				dfs(i, j);
				cnt++;
			}
		}
	}
	bridgeMap.resize(cnt, vector<int>(cnt, 10));
	
	// ���� ������ ������ �ٸ��� �ּұ��̷� ǥ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				checkBridge(i, j, map[i][j]);
			}
		}
	}
	
	// �ٸ��� �ּڰ� ���ϱ�
	for (int i = 1; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (bridgeMap[i][j] != 10) {
				candidate.push_back({ i,j,bridgeMap[i][j] });
			}
		}
	}
	pick = cnt - 2;
	// �ּ����� �ٸ� ������ �������� ���� ���, ��� �ٸ��� �ձ�� �Ұ�����.
	if (pick>candidate.size()) {
		cout << -1 << endl;
		return 0;
	}
	tmp.resize(candidate.size());
	while (pick != candidate.size()+1) {
		combinationBridge(0, 0);
		pick++;
	}

	// ����� ���
	if (answer != MAX) {
		cout << answer << endl;
	}
	else {
		cout << -1 << endl;
	}
}