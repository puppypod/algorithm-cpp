#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int visit[1000001][11];
queue<pair<string, int>> q;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	int K, answer = 0;
	cin >> str >> K;

	q.push(make_pair(str, 0));
	while (!q.empty()) {
		pair<string, int> cur = q.front(); q.pop();
		if (cur.second == K) { // K번 연산했을 경우
			answer = max(answer, stoi(cur.first));
			continue;
		}
		string curStr = cur.first;
		for (int i = 0; i < curStr.size() - 1; i++) {
			for (int j = i + 1; j < curStr.size(); j++) {
				swap(curStr[i], curStr[j]);
				// 맨앞이 0 이거나 이미 방문한 적이 있으면
				if (curStr[0] == '0' || visit[stoi(curStr)][cur.second + 1]) { 
					swap(curStr[i], curStr[j]); // 다시 되돌려줌 
					continue;
				}
				q.push(make_pair(curStr, cur.second + 1)); //swap한 string, 연산횟수+1
				visit[stoi(curStr)][cur.second + 1] = 1;
				swap(curStr[i], curStr[j]); // 다시 되돌려줌
			}
		}
	}
	if (answer == 0) cout << "-1";
	else cout << answer;
	
}
