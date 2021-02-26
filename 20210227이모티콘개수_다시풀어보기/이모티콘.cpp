#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
int n;
int visit[1001][1001]; // -> ����ȭ���̸�Ƽ�ܰ��� / Ŭ�����尳��

int bfs() {
	queue<pair<int, pair<int,int>>> q;
	int sec = 0;
	int screen = 1;
	int clip = 0;
	q.push({ sec, {screen,clip} });
	while (!q.empty()) { // ����, �ٿ��ֱ�, ���� -> ���� 1�ʾ�
		sec = q.front().first; // �ð���
		screen = q.front().second.first; // ����ȭ�� �̸�Ƽ�� ����
		clip = q.front().second.second; // ���� Ŭ���������
		q.pop();
		if (screen == n) {
			break;
		}

		if (screen >= 1 && screen <= 1000) {
			// Ŭ������ ����
			if (!visit[screen][screen]) {
				visit[screen][screen] = 1;
				q.push({ sec + 1,{screen,screen} });
			}
			// �ٿ��ֱ�
			if (clip > 0 && screen + clip <= 1000) {
				if (!visit[screen + clip][clip]) {
					visit[screen + clip][clip] = 1;
					q.push({ sec + 1,{screen + clip,clip} });
				}
			}
			// ����
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