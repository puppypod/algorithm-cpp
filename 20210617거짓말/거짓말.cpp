#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> parents;

int find(int idx) {
	if (parents[idx] == idx) {
		return parents[idx];
	}
	return parents[idx] = find(parents[idx]);
}
void merge(int parent, int child) {
	parents[child] = parents[parent];
}
// MST
int main()
{
	int N, M;
	// N -> ���, M -> ����
	cin >> N >> M;
	parents.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		parents[i] = i;
	}

	int truePerson;
	int p = 0;
	// ������ �ƴ� ����� ��
	cin >> truePerson;
	set<int> s;
	if (truePerson >= 1) {
		cin >> p;
		s.insert(p);
		for (int i = 0; i < truePerson - 1; i++) {
			// ������ �ƴ� ����� ��ȣ
			int num;
			cin >> num;
			s.insert(num);
			merge(p, num);
		}
	}
	// �� ��Ƽ�帶�� ���� ��� �� �� ��ȣ
	vector<int> party[50];
	for (int i = 0; i < M; i++) {
		// i�� ��Ƽ�� ��ȣ
		int num;
		cin >> num;
		int prev;
		if (num >= 1) {
			cin >> prev;
			party[i].push_back(prev);
			for (int j = 0; j < num-1; j++) {
				// ��� ��ȣ
				int ID;
				cin >> ID;
				party[i].push_back(ID);
				int parent1 = find(prev);
				int parent2 = find(ID);
				// �θ�� ������ ������ ����
				if (parent1 != parent2) {
					if (p == parent1) {
						merge(parent1, parent2);
					}
					else if (p == parent2) {
						merge(parent2, parent1);
					}
					else {
						merge(parent1, parent2);
					}
				}
			}
		}
	}

	for (int i = 1; i < parents.size(); i++) {
		// ���� parents ���ϱ�
		find(i);
	}
	// ������ �˰��ִ� ����� ���� ��
	for (int i = 1; i < parents.size(); i++) {
		if (p == parents[i]) {
			s.insert(i);
		}
	}
	int answer = 0;
	for (int i = 0; i < M; i++) {
		bool isFalse = false;
		for (int tmp : party[i]) {
			if (s.find(tmp) != s.end()) {
				isFalse = true;
			}
		}
		if (!isFalse) {
			answer++;
		}
	}
	cout << answer;
}