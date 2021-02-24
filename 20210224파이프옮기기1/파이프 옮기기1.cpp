#include<iostream>
#include<vector>
using namespace std;

int map[17][17];
int pipe[2][2]; // ������ ����, ������ ��ġ ��ǥ

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> horizontal(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> vertical(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> diagonal(n + 1, vector<int>(n + 1, 0));

	//�Է�
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	// dp ����
	// ���� -> ���� + �밢��
	// ���� -> ���� + �밢��
	// �밢�� -> ���� + ���� + �밢��
	// ��, �밢���� diagonal[n][n]�� ����ϸ� ���ϴ� ������� ���� �� ����.
	for (int i = 2; i <= n; i++) {
		if (map[1][i] == 1)break;
		horizontal[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != 1) {
				horizontal[i][j] = horizontal[i][j-1] + diagonal[i][j-1];
				vertical[i][j] = vertical[i-1][j] + diagonal[i-1][j];

				if (map[i-1][j]!=1 && map[i][j-1]!=1) {
					diagonal[i][j] = horizontal[i-1][j-1] +
						vertical[i-1][j-1] + diagonal[i-1][j-1];
				}
			}
		}
	}
	
	cout << horizontal[n][n]+ vertical[n][n] + diagonal[n][n] << endl;
}