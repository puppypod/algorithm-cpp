#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<pair<int,int>> things;
int v_mx = -1;
bool isEnd;
void dfs(int idx, int w_sum, int v_sum) {
	if (w_sum <= K) {
		v_mx = max(v_mx, v_sum);
	}
	else { isEnd = true; return; }
	
	for (int i = idx; i < N; i++) {
		dfs(i + 1, w_sum + things[i].first, v_sum + things[i].second);
		if (isEnd) {
			isEnd = false;
			break;
		}
	}
	return;
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		things.push_back({ w,v });
	}
	sort(things.begin(), things.end());
	isEnd = false;
	dfs(0, 0, 0);
	cout << v_mx << endl;
}