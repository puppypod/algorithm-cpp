#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	int candidate[101] = { 0, };
	cin >> N >> K;
	// ù��°�� ��ȣ
	// �ι�°�� �Է� �� idx �� -> ������ ������ ã�� ����.
	vector<pair<int, int>> v(N);

	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		candidate[n]++;
		bool flag = true;
		for (int j = 0; j < N; j++) {
			// new �ĺ���
			if (v[j].first == 0) {
				v[j].first = n;
				v[j].second = i;
				flag = false;
				break;
			}
			// �ߺ� �ĺ���
			else if (v[j].first == n)
			{ 
				flag = false; break;
			}
		}
		// ������ �����ִٸ�
		if (flag) {
			int idx = 0;
			for (int j = 1; j < N; j++) {
				// ���� ��ǥ�� �ĺ��� ���ϱ�
				if (candidate[v[idx].first] > candidate[v[j].first]) {
					idx = j;
				}
				// ���� ��ǥ���� �����Ѵٸ�
				else if (candidate[v[idx].first] == candidate[v[j].first]) {
					// ���� ��ϵ� ���̶�� swap
					if (v[idx].second > v[j].second) {
						idx = j;
					}
				}
			}
			// �ĺ����� �����
			candidate[v[idx].first] = 0;

			v[idx].first = n;
			v[idx].second = i;
		}
	}
	vector<int> answer;
	for (int i = 0; i < N; i++) {
		answer.push_back(v[i].first);
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}