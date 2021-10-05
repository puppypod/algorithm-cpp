#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

vector<long long> v;
set<long long> visited;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, K;
	cin >> K >> N;

	
	for (int i = 0; i < K; i++) {
		long long n; cin >> n;
		v.push_back(n);
	}

	long long maxValue = 0;
	pq.push(1);

	while (N) {
		long long number = pq.top();
		pq.pop();
		//cout << number << endl;

		for (int i = 0; i < K; i++) {
			long long newNum = number * v[i];

			// - ���ǹ� ����
			// pq�� �����ִ��� ���Ӱ� �� �Ҽ��� ���� pq�� �ִ񰪺��� �۴ٸ�
			// pq�� �־��־�� ��� ����� ������ ������ �� �ִ�.
			
			// �ݴ�� pq�� �� ��������, ���Ӱ� �� �Ҽ��� ���� pq�� �ִ񰪺���
			// ũ�ٸ�, �� �̻� �ǹ̾��� ���� �ȴ�.
			if (pq.size() >= N && newNum > maxValue) break;

			if (visited.find(newNum) == visited.end()) {
				visited.insert(newNum);
				pq.push(newNum);
				maxValue = max(maxValue, newNum);
			}
		}

		N--;
	}
	
	cout << pq.top();
}