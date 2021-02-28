#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

vector<int> primeNum;
vector<int> answer;
void bfs(int n) {
	queue<pair<int, int>> q;
	vector<int> tmp;
	int num, cnt;
	q.push({ 2,1 });
	q.push({ 3,1 });
	q.push({ 5,1 });
	q.push({ 7,1 });
	tmp.push_back(1);
	tmp.push_back(3);
	tmp.push_back(7);
	tmp.push_back(9);
	int candidateNum;
	while (!q.empty()) {
		num = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (cnt == n) {
			answer.push_back(num);
		}
		else if (cnt > n) { break; }
		for (int i = 0; i < 4; i++) {
			candidateNum = num * 10 + tmp[i];
			bool isTrue = true;
			for (auto a : primeNum) {
				if (a > sqrt(candidateNum)) { break; }
				if (candidateNum % a == 0) {
					isTrue = false;
					break;
				}
			}
			if (isTrue) { // 소수가 맞다는 의미, cnt는 자릿수
				q.push({ candidateNum,cnt + 1 });
			}
		}
		
	}
}
void isPrime() {
	int num = 5;
	while (num != 32001) {
		bool isTrue = true;
		for (int i = 3; i <= sqrt(num); i++) {
			if (num % i==0) {
				isTrue = false;
				break;
			}
		}
		if (isTrue) {
			primeNum.push_back(num);
		}
		num += 2;
	}
}
int main()
{
	int n;
	cin >> n;
	primeNum.push_back(2);
	primeNum.push_back(3);
	isPrime();
	bfs(n);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}