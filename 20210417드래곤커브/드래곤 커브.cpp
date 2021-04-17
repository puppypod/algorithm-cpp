#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = { {0,1} ,{-1,0} ,{0,-1} ,{1,0} };
int checkBox[3][2] = { {0,1} ,{1,1} ,{1,0} };
vector<vector<int>> result_map(101, vector<int>(101, 0));

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> dirV;
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		result_map[y][x] = 1;
		dirV.push_back(d);

		// 커브 경로 저장
		for (int j = 0; j < g; j++) {
			int length = dirV.size();
			for (int k = length-1; k >=0; k--) {
				dirV.push_back((dirV[k] + 1) % 4);
			}
		}

		// 저장된 커브 경로에 따라 map에 저장
		for (int j = 0; j < dirV.size(); j++) {
			y += dir[dirV[j]][0];
			x += dir[dirV[j]][1];
			result_map[y][x] = 1;
		}
	}
	int answer = 0;
	// 1x1 정사각형 개수 세기
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (result_map[i][j]) {
				// 정사각형 검사
				bool isBox = true;
				for (int k = 0; k < 3; k++) {
					if (!result_map[i + checkBox[k][0]][j + checkBox[k][1]]) {
						isBox = false;
						break;
					}
				}
				if (isBox) {
					answer++;
				}
			}
		}
	}
	cout << answer << '\n';
}