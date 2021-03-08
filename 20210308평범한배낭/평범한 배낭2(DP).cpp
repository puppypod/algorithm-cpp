#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> W;
vector<int> V;
// DP에 들어갈 값은 Value의 최댓값
vector<vector<int>> DP;

int solution() {
	// 1번째 아이템부터 N번째 아이템까지 점검
	for (int i = 1; i <= N; i++) {
		// i번째 아이템까지 고려를 했을 때, weight 1부터 weight K까지의 최대 value 구하기
		for (int j = 1; j <= K; j++) {
			if (j >= W[i]) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	return DP[N][K];
}
int main()
{
	cin >> N >> K;
	DP.resize(N+1, vector<int>(K+1, 0));
	W.push_back(0);
	V.push_back(0);
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		W.push_back(w);
		V.push_back(v);
	}
	cout << solution() << endl;

}