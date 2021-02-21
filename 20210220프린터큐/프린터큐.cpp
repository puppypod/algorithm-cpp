#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	
	int t;
	int n, idx;
	int answer;
	int num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		queue<int> q;
		priority_queue<int> pq;
		cin >> n >> idx;
		for (int j = 0; j < n; j++) {
			cin >> num;
			q.push(num);
			pq.push(num);
		}
		int qSize;
		int next_num;
		int tmp;
		bool isTrue = false;
		answer = 0;
		while (1) {
			answer++;
			qSize = q.size();
			next_num = pq.top();
			pq.pop();
			for (int j = 0; j < qSize; j++) {
				if (q.front() != next_num) {
					idx--;
					tmp = q.front();
					q.push(tmp);
					q.pop();
				}
				else { // Ãâ·Â
					if (idx == 0) {
						isTrue = true;
					}
					idx--;
					q.pop();
					break;
				}
				if (idx < 0) { idx = qSize - 1; }

			}
			if (isTrue) { break; }
		}
		cout << answer << endl;
	}
	
}