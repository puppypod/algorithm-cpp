#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> visit(100001, 0);
vector<int> parents(100001, 0);
vector<int> answer;
int min_cnt;
void bfs(int a, int b) {
	queue<pair<int,int>> q;
	int prev = a;
	q.push({ a,0 });
	int cnt = 0;
	while (!q.empty()) {
		a = q.front().first;
		cnt = q.front().second;
		q.pop();
		
		if (a == b) {
			int idx = a;
			while (idx != prev) {
				answer.push_back(idx);
				idx = parents[idx];
			}
			answer.push_back(idx);
			break;
		}
		
		if (a * 2 <= 100000 && !visit[a * 2]) {
			visit[a * 2] = 1;
			q.push({ a * 2,cnt + 1 });
			parents[a * 2] = a;
		}
		
		if (a + 1 <= 100000 && !visit[a + 1]) {
			visit[a + 1] = 1;
			q.push({ a + 1,cnt + 1 });
			parents[a + 1] = a;
		}
		
		if (a - 1 >= 0 && !visit[a - 1]) {
			visit[a - 1] = 1;
			q.push({ a - 1,cnt + 1 });
			parents[a - 1] = a;
		}
	}
	min_cnt = cnt;
}

int main()
{
	int n, k;
	cin >> n >> k;
	bfs(n, k);
	visit[n] = 0;
	cout << min_cnt << endl;
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}
	cout << endl;
}