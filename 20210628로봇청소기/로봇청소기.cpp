#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M; // 맵 크기
int r, c, d; // 현재 로봇청소기 위치 및 방향
vector<vector<int>> house;
// 북0, 동1, 남2, 서3
// -1 -> 왼쪽 방향으로
int dir[4][2] = { {-1,0} ,{0,1}, {1,0} , {0,-1} };

int main()
{
	cin >> N >> M;
	cin >> r >> c >> d;
	house.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> house[i][j];
		}
	}

	/*
	* 1. 현재 위치를 청소
	* 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터  차례로 탐색을 진행
		- 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 
		  그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.

		- 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.

		- 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 
		  바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.

		- 네 방향 모두 청소가 이미 되어있거나 벽이면서, 
		  뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
	*/

	// -1은 청소했다는 의미
	house[r][c] = 2;
	// 현재위치는 항상 비어있고, 비어있는 공간은 항상 청소해야하기 때문
	int answer = 1; 
	while (1) {
		// 값이 4가 된다면, 네 방향 모두 이미 청소한 공간이라는 의미
		int isNotDir = 0;
		int dy, dx;
		for (int i = 0; i < 4; i++) {
			d--;
			if (d < 0) d = 3;
			dy = r + dir[d][0];
			dx = c + dir[d][1];
			// 검색 방향이 비어있다면
			if (house[dy][dx] == 0) {
				// 청소하러 가기
				house[dy][dx] = 2;
				answer++;
				break;
			}
			else {
				isNotDir++;
			}
		}

		if (isNotDir != 4) {
			r = dy;
			c = dx;
		}
		// 4방향 모두 이미 청소되어 있거나 벽이라면
		else {
			// d는 유지하면서 후진하기
			int goY = r + dir[(d + 2) % 4][0];
			int goX = c + dir[(d + 2) % 4][1];
			if (house[goY][goX] == 1) {
				//후진하는 방향이 벽인 경우 청소 종료;
				break;
			}
			r = goY;
			c = goX;
		}
	}
	cout << answer << endl;
}