#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
int n;
int visit[1001][1001]; // -> 현재화면이모티콘개수 / 클립보드개수

int bfs() {
	queue<pair<int, pair<int,int>>> q;
	int sec = 0;
	int screen = 1;
	int clip = 0;
	q.push({ sec, {screen,clip} });
	while (!q.empty()) { // 복사, 붙여넣기, 삭제 -> 각각 1초씩
		sec = q.front().first; // 시간초
		screen = q.front().second.first; // 현재화면 이모티콘 개수
		clip = q.front().second.second; // 현재 클립보드상태
		q.pop();
		if (screen == n) {
			break;
		}

		if (screen >= 1 && screen <= 1000) {
			// 클립보드 복사
			if (!visit[screen][screen]) {
				visit[screen][screen] = 1;
				q.push({ sec + 1,{screen,screen} });
			}
			// 붙여넣기
			if (clip > 0 && screen + clip <= 1000) {
				if (!visit[screen + clip][clip]) {
					visit[screen + clip][clip] = 1;
					q.push({ sec + 1,{screen + clip,clip} });
				}
			}
			// 삭제
			if (!visit[screen - 1][clip]) {
				visit[screen - 1][clip] = 1;
				q.push({ sec + 1,{screen - 1,clip} });
			}
		}
	}
	return sec;
}
int main()
{
	cin >> n;
	cout << bfs() << endl;
}