#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define K_MAX 1000000000

int N, M, K;
int dp[201][201]{ 0 };
string str = "";

int combination(int n, int r) {
	if (n == r || r == 0) { // ���ڸ��� ��� 1�̱� ������
		return 1;
	}
	else if (dp[n][r] != 0) { // Hit �ߴٸ� �� ��ȯ
		return dp[n][r];
	}
	else { // ��� ������ ���� �������
		return dp[n][r] = min(K_MAX, combination(n - 1, r - 1) + combination(n - 1, r));
	}
}
void query(int n, int m, int k) {
	if (n + m == 0) { // ���� ����
		cout << str;
		return;
	}
	else if (n == 0) {
		str.push_back('z');
		query(n, m - 1, k);
	}
	else if (m == 0) {
		str.push_back('a');
		query(n - 1, m, k);
	}
	else {
		int leftCount = combination(n + m - 1, m);
		if(leftCount >= k){
			
			str.push_back('a');
			query(n - 1, m, k);
		}
		else {
			str.push_back('z');
			query(n, m - 1, k - leftCount);
		}
	}

}
int main()
{
	cin >> N >> M >> K;
	if (combination(N + M, M) >= K) {
		query(N, M, K);
	}
	else {
		cout << -1;
	}
}