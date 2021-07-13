#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> cpy;
vector<vector<int>> visit;
vector<pair<int, int>> candidate;
vector <pair<int, int>> tmp;
int dir[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };
int N, M;
int counter = 0;
int counterCpy;
int answer = 2500;

bool isTrue(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}
int infection() {
	// Ȱ��ȭ�� ���̷����� �����ϴ� ��ǥ
	queue<pair<pair<int, int>,int>> q;
	for (pair<int, int> t : tmp) {
		visit[t.first][t.second] = 1;
		q.push({ t,0 });
	}
	int r;
	int c;
	int cnt;
	while (!q.empty()) {
		r = q.front().first.first;
		c = q.front().first.second;
		cnt = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = r + dir[i][0];
			int dx = c + dir[i][1];

			// ������ ����ų� �̹� �湮�� ���̶��
			if (!isTrue(dy, dx) || visit[dy][dx]) continue;

			// ��ĭ �Ǵ� ���̷������
			if (map[dy][dx] <= 0) {
				if (map[dy][dx] == 0) {
					counterCpy--;
					if (counterCpy == 0) {
						return cnt + 1;
					}
					map[dy][dx] = cnt + 1;
				}
				visit[dy][dx] = 1;
				q.push({ { dy,dx }, cnt + 1 });
				
			}
		}
	}
	return -1;
}
void pickVirus(int a, int b) {
	if (b == M) {
		// �ʱ� ������ map ����. �޸����̼�
		vector<vector<int>> init(N, vector<int>(N, 0));
		cpy = map;
		int a;
		visit = init;
		counterCpy = counter;
		if ((a = infection()) != -1) {
			answer = min(a, answer);
		}

		map = cpy;
		return;
	}
	for (int i = a; i < candidate.size(); i++) {
		tmp[b].first = candidate[i].first;
		tmp[b].second = candidate[i].second;
		pickVirus(i + 1, b + 1);
	}
}
int main()
{
	cin >> N >> M;
	map.resize(N, vector<int>(N));
	tmp.resize(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			// ���̷����� ���ϰ� �ؾ��ϴ� ��ĭ�� ���� count
			if (map[i][j] == 0) {
				counter++;
			}
			// ���̷��� �ĺ��� �̱�
			else if (map[i][j] == 2) {
				map[i][j] = -1;
				candidate.push_back({ i,j });
			}
		}
	}
	if (counter == 0) {
		cout << 0;
	}
	else {
		pickVirus(0, 0);
		if (answer == 2500) cout << -1;
		else cout << answer;
	}
	return 0;
}