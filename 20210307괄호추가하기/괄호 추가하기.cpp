#include <iostream>
#include <vector>

using namespace std;

string v;
int n;
int mx = -2100000000;
int calc(int sum, int num, char c) {
	if (c == '+') {
		sum += num;
	}
	else if (c == '-') {
		sum -= num;
	}
	else if (c == '*') {
		sum *= num;
	}
	return sum;
}
void dfs(int idx, int sum) {
	if (idx >= n) {
		mx = max(mx, sum);
		return;
	}
	char c = (idx != 0) ? v[idx - 1] : '+';
	int tmp = calc(sum, v[idx] - 48, c);

	// 순차적으로 더하는 경우
	dfs(idx + 2, tmp); 
	
	if (idx < n - 2) {
		// 괄호를 묶은 후, 앞 연산자와 연산 진행
		tmp = calc(v[idx] - 48, v[idx + 2] - 48, v[idx + 1]);
		tmp = calc(sum, tmp, c);
		dfs(idx + 4, tmp);
	}
	return;
}
int main()
{
	cin >> n;
	cin >> v;
	
	dfs(0,0);
	cout << mx << endl;
}