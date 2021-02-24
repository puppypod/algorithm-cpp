#include<iostream>
#include<vector>
using namespace std;

int map[17][17];
int pipe[2][2]; // 파이프 왼쪽, 오른쪽 위치 좌표

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> horizontal(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> vertical(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> diagonal(n + 1, vector<int>(n + 1, 0));

	//입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	// dp 시작
	// 가로 -> 가로 + 대각선
	// 세로 -> 세로 + 대각선
	// 대각선 -> 가로 + 세로 + 대각선
	// 즉, 대각선의 diagonal[n][n]을 출력하면 원하는 결과값을 얻을 수 있음.
	for (int i = 2; i <= n; i++) {
		if (map[1][i] == 1)break;
		horizontal[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != 1) {
				horizontal[i][j] = horizontal[i][j-1] + diagonal[i][j-1];
				vertical[i][j] = vertical[i-1][j] + diagonal[i-1][j];

				if (map[i-1][j]!=1 && map[i][j-1]!=1) {
					diagonal[i][j] = horizontal[i-1][j-1] +
						vertical[i-1][j-1] + diagonal[i-1][j-1];
				}
			}
		}
	}
	
	cout << horizontal[n][n]+ vertical[n][n] + diagonal[n][n] << endl;
}