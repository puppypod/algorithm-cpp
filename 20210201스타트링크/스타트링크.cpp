#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int f, s, g, u, d;
int bfs() {
	queue<pair<int,int>> q;
	vector<int> visit(f,0);
	visit[s - 1] = 1;
	q.push(make_pair(s,0));
	int floor = s;
	int cnt = 0;
	while (!q.empty()) {
		floor = q.front().first;
		cnt = q.front().second;
		if (floor == g) { break; }
		q.pop();
		if (floor + u <= f && !visit[floor + u - 1]) {
			visit[floor + u - 1] = 1;
			q.push(make_pair(floor + u, cnt + 1));
		}
		if (floor - d >= 1 && !visit[floor - d - 1]) {
			visit[floor - d - 1] = 1;
			q.push(make_pair(floor - d, cnt + 1));
		}
	}
	if (floor != g) { return -1; }
	return cnt;
}
int main()
{
	cin >> f >> s >> g >> u >> d;
	int result = bfs();
	if(result != -1){
		cout << bfs() << endl;
	}
	else {
		cout << "use the stairs" << endl;
	}
	return 0;
}