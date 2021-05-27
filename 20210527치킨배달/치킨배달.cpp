#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> map;
int N, M, K;
vector<pair<int, int>> candidate;
vector<pair<int, int>> user;
vector<int> tmp;
int answer = 987654321;

void dfs(int a, int b, int cnt) {
	if (b == cnt) {
		int sum = 0;

		for (int i = 0; i < user.size(); i++) {
			int userx = user[i].first;
			int usery = user[i].second;
			int mn = 101;
			for (int a : tmp) {
				int chickenx = candidate[a].first;
				int chickeny = candidate[a].second;
				int tmpSum = abs(userx - chickenx) + abs(usery - chickeny);
				mn = min(mn, tmpSum);
			}
			sum += mn;
		}
		answer = min(answer, sum);
		return;
	}

	for (int i = a; i < K; i++) {
		tmp[b] = i;
		dfs(i + 1, b + 1, cnt);
	}
}
int main()
{
	cin >> N >> M;
	map.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				user.push_back({ i,j });
			}
			if (map[i][j] == 2) {
				candidate.push_back({ i,j });
			}
		}
	}
	K = candidate.size();
	for (int i = 1; i <= M; i++) {
		vector<int> init(i);
		tmp = init;
		dfs(0, 0, i);
	}
	cout << answer;
}