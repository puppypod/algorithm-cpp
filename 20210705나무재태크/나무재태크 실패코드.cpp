#include <iostream>
#include <vector>
#include <cmath> // trunc() �Լ� ���(�Ҽ��� ���� �Լ�)
#include <queue>

using namespace std;

int N, M, K;
vector<vector<int>> A;
// filed[r][c][0] == �� ���� �����ϴ� ��� ũ��
// filed[r][c][1~n] == �� ���� �����ϴ� �������� ����(������������ �����ϴ� ���� �߿���.)
vector<vector<vector<int>>> field;
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> trees;
queue<vector<int>> dieTree;
queue<vector<int>> fiveTree;
int dir[8][2] = { {0,1} ,{0,-1} ,{1,0} ,{-1,0} ,{-1,-1} ,{1,1} ,{1,-1} ,{-1,1} };

bool isTrue(int r, int c) {
	return r >= 1 && r <= N && c >= 1 && c <= N;
}
void spring() {
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> tmp;
	while (!trees.empty()) {
		int x = trees.top()[0];
		int y = trees.top()[1];
		int z = trees.top()[2];
		
		for (int i = field[x][y].size()-1; i >= 1; i--) {
			
			if (z <= field[x][y][0]) {
				// 1�� ���� ����
				field[x][y][i]++;
				// 5����� ���̸� ������ ����
				if (field[x][y][i] % 5 == 0) {
					fiveTree.push({ x,y,field[x][y][i] });
				}
				field[x][y][0] -= z;
				tmp.push({ x,y, field[x][y][i] });
			}
			else {
				// ���� ����
				dieTree.push({ x,y,z });
			}
			trees.pop();
			if (!trees.empty()) {
				x = trees.top()[0];
				y = trees.top()[1];
				z = trees.top()[2];
			}
		}
	}
	while (!tmp.empty()) {
		trees.push(tmp.top());
		tmp.pop();
	}
}
void summer() {
	while (!dieTree.empty()) {
		int x = dieTree.front()[0];
		int y = dieTree.front()[1];
		int z = dieTree.front()[2];
		dieTree.pop();
		// ���� ������ ��� �߰�
		int plusNum = trunc(z / 2);
		field[x][y][0] += plusNum;
	}
}
void autumn() {
	// ������ ����
	while (!fiveTree.empty()) {
		int x = fiveTree.front()[0];
		int y = fiveTree.front()[1];
		int z = fiveTree.front()[2];
		fiveTree.pop();
		for (int i = 0; i < 8; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			if (isTrue(dx, dy)) {
				field[dx][dy].push_back(1);
				trees.push({ dx,dy,1 });
			}
		}
	}
}
void winter() {
	// ��� ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			field[i][j][0] += A[i][j];
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	A.resize(N + 1, vector<int>(N + 1));
	// �ʱ� ��� ���� 5
	field.resize(N + 1, vector<vector<int>>(N + 1, vector<int>(1, 5)));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		// �Ŀ� ����� �ִ� ������ �� ��ĭ���� 1������� ����� �־����.
		// ���̰� � ������ ����� �־���ϱ� ������
		// ���� ������ .erase()�� �̿��Ͽ� ǥ��
		field[x][y].push_back(z);
		trees.push({ x,y,z });
	}

	for (int i = 0; i < K; i++) {
		// ��
		spring();
		// ����
		summer();
		// ����
		autumn();
		//�ܿ�
		winter();
	}
	cout << trees.top()[2] << endl;
	cout << trees.size();
	
}