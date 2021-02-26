#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 10e9
long long bfs(long long a, long long b) {
	queue<pair<long,long>> q; // ÇöÀç°ª, count
	q.push({ a,1 });
	int cnt;
	bool isMatch = false;
	int answer = -1;
	while (!q.empty()) {
		a = q.front().first;
		cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 2; i++) {
			if (i == 0) { // *2
				if ( a * 2 <= b*2) {
					if (a * 2 == b) {
						isMatch = true;
						answer = cnt + 1;
						break;
					}
					q.push({ a * 2,cnt + 1 });
				}
			}
			else { // A+1 -> A1
				if (a * 10 + 1 <= b*10 + 1) {
					if (a * 10 + 1 == b) {
						isMatch = true;
						answer = cnt + 1;
						break;
					}
					q.push({ a * 10 + 1,cnt + 1 });
				}
			}
		}
		if (isMatch) {
			break;
		}
	}
	return answer;
}
int main()
{
	long long a, b;
	cin >> a >> b;
	cout << bfs(a, b) << endl;
}