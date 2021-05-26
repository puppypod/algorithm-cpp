#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321
vector<int> DP[3];
int N;
vector<vector<int>> colorList;

int main()
{
	cin >> N;
	DP[0].resize(N, INF);
	DP[1].resize(N, INF);
	DP[2].resize(N, INF);
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		colorList.push_back({ a,b,c });
	}
	// »¡°­, ÃÊ·Ï, ÆÄ¶û ¼øÀ¸·Î
	DP[0][0] = colorList[0][0];
	DP[1][0] = colorList[0][1];
	DP[2][0] = colorList[0][2];
	for (int i = 1; i < colorList.size(); i++) {
		for (int j = 0; j < 3; j++) {
			DP[j][i] = min(DP[j][i], DP[(j + 1) % 3][i - 1] + colorList[i][j]);
			DP[j][i] = min(DP[j][i], DP[(j + 2) % 3][i - 1] + colorList[i][j]);
			
		}
	}
	int answer = INF;
	for (int i = 0; i < 3; i++) {
		answer = min(answer, DP[i][N - 1]);
	}
	cout << answer;
}