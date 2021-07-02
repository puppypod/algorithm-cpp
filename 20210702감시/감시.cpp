#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
//1~5 : CCTV
//6 : 벽
//음수 : cctv감시구역
vector<vector<int>> map;

vector<vector<pair<int,int>>> dir[6];
vector<pair<int, int>> cctv;

int answer = 64;

bool isTrue(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}
void dfs(vector<vector<int>> cpy, int nextID) {
	if (nextID == cctv.size()) {
		// 모든 cctv의 세팅이 끝났다면
		int cnt = 0;
		//cout << endl;
		for (int i = 0; i < cpy.size(); i++) {
			for (int j = 0; j < cpy[i].size(); j++) {
				//cout << cpy[i][j] << " ";
				if (cpy[i][j] == 0) {
					cnt++;
				}
			}
			//cout << endl;
		}
		answer = min(answer, cnt);

		return;
	}

	// cctv ID 구하기
	int r = cctv[nextID].first;
	int c = cctv[nextID].second;
	int cctvID = cpy[r][c];

	for (int j = 0; j < dir[cctvID].size(); j++) {
		int dy, dx;
		vector<pair<int, int>> backInfo;
		for (int k = 0; k < dir[cctvID][j].size(); k++) {
			dy = r + dir[cctvID][j][k].first;
			dx = c + dir[cctvID][j][k].second;
			
			while (isTrue(dy, dx) && cpy[dy][dx] != 6) {
				if (cpy[dy][dx] <= 0 ) {
					cpy[dy][dx] -= 1;
					backInfo.push_back({ dy,dx });
				}

				dy += dir[cctvID][j][k].first;
				dx += dir[cctvID][j][k].second;
			}
			
		}
		dfs(cpy, nextID + 1);
		for (int a = 0; a < backInfo.size(); a++) {
			cpy[backInfo[a].first][backInfo[a].second] += 1;
		}
	}

}
int main()
{
	cin >> N >> M;
	map.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			// cctv 위치 정보
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv.push_back({ i,j });
			}
		}
	}

	// 1 ~ 5 cctv 정보 세팅
	dir[1].push_back({ { 0,1 } }); dir[1].push_back({ { 0,-1 } });
	dir[1].push_back({ { 1,0 } }); dir[1].push_back({ { -1,0 } });

	dir[2].push_back({ {0,1},{0,-1} }); dir[2].push_back({ {1,0},{-1,0} });

	dir[3].push_back({ {-1,0},{0,1} }); dir[3].push_back({ {0,1},{1,0} });
	dir[3].push_back({ {1,0},{0,-1} }); dir[3].push_back({ {0,-1},{-1,0} });

	dir[4].push_back({ {0,-1} ,{-1,0} ,{0,1} }); dir[4].push_back({ {-1,0} ,{0,1} ,{1,0} });
	dir[4].push_back({ {0,-1} ,{1,0} ,{0,1} }); dir[4].push_back({ {-1,0} ,{0,-1} ,{1,0} });

	dir[5].push_back({ {0,1} ,{1,0} ,{0,-1} ,{-1,0} });

	dfs(map, 0);

	cout << answer;

}