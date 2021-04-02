#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> personArr;
vector<vector<int>> map;
vector<int> visit_cpy;
vector<int> candidate;
vector<int> tmp(10, 0);
vector<int> rest;
int mn = 10000;

int A, B;
int pick;

void checkA(int v) { // 선거구 A Check
	visit_cpy[v] = 1;
	for (int i = 0; i < pick; i++) {
		if (!visit_cpy[tmp[i]] && map[v][tmp[i]]) {
			checkA(tmp[i]);
		}
	}
	return;
}
void checkB(int v) { // 선거구 B Check
	visit_cpy[v] = 1;
	for (int i = 0; i < rest.size(); i++) {
		if (!visit_cpy[rest[i]] && map[v][rest[i]]) {
			checkB(rest[i]);
		}
	}
	return;
}
void dfs(int a, int b) {
	if (b == pick) {
		vector<int> visit(N, 0);
		visit_cpy = visit;
		// 뽑은 구역이 인접한지 확인
		checkA(tmp[0]);
		A = 0;
		for (int checkNum = 0; checkNum < b; checkNum++) {
			A += personArr[tmp[checkNum]];
			if (!visit_cpy[tmp[checkNum]]) {
				return;
			}
		}
		// 나머지 구역이 인접한지 확인

		// 나머지 구역을 rest에 저장
		rest.clear();
		for (int i = 0; i < N; i++) {
			bool flag = true;
			for (int checkNum = 0; checkNum < b; checkNum++) {
				if (i == tmp[checkNum]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				rest.push_back(i);
			}
		}
		
		checkB(rest[0]);
		B = 0;
		for (int checkNum : rest) {
			B += personArr[checkNum];
			if (!visit_cpy[checkNum]) {
				return;
			}
		}

		// 결과 값
		mn = min(mn, abs(A - B));

		return;
	}

	// 조합 알고리즘
	for (int i = a; i < N; i++) {
		tmp[b] = candidate[i];
		dfs(i + 1, b + 1);
	}
}
int main()
{
	cin >> N;
	personArr.resize(N);
	map.resize(N, vector<int>(N));
	visit_cpy.resize(N, 0);
	candidate.resize(N, 0);
	// 각 구역의 인구수
	for (int i = 0; i < N; i++) {
		cin >> personArr[i];
	}
	// 구역 map 세팅
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int a;
			cin >> a;
			map[i][a - 1] = 1;
			map[a - 1][i] = 1;
		}
	}

	// 선거구가 될 수 있는 구역들의 집합
	for (int i = 0; i < N; i++) {
		candidate[i] = i;
	}
	int cnt = N / 2;
	for (int i = 1; i <= cnt; i++) {
		// 몇개를 뽑을지 결정해주는 변수
		pick = i;
		dfs(0, 0);
	}
	if (mn != 10000) {
		cout << mn << endl;
	}
	else {
		cout << -1 << endl;
	}
}