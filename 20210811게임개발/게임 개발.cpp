#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> inDegree;
vector<int> info[501];
vector<int> timeMax;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;

	queue<int> q;
	inDegree.resize(N + 1);
	timeMax.resize(N + 1);
	vector<long long> answer(N + 1);


	for (int i = 1; i <= N; i++) {
		long long time;
		cin >> time;
		answer[i] = time;
		int num;
		cin >> num;
		while (num != -1) {
			info[num].push_back(i);
			inDegree[i]++;

			cin >> num;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int num = q.front();
		q.pop();


		for (int i = 0; i < (int)info[num].size(); i++) {
			int next = info[num][i];
			inDegree[next]--;
			if (timeMax[next] < answer[num]) {
				timeMax[next] = answer[num];
			}
			if (inDegree[next] == 0) {

				answer[next] += timeMax[next];
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << answer[i] << '\n';
	}
}