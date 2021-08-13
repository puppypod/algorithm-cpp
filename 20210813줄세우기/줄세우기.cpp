#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> inDegree;
vector<int> info[320001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;
	
	queue<int> q;
	inDegree.resize(N + 1);

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
		inDegree[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int num = q.front();
		cout << num << " ";
		q.pop();

		for (int i = 0; i < info[num].size(); i++) {
			int next = info[num][i];
			inDegree[next]--;
			if (inDegree[next] == 0) {
				q.push(next);
			}
		}
	}
}