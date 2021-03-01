#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	priority_queue<int, vector<int>, greater<int>> m_arr;
	priority_queue<int> p_arr;
	int zero_cnt = 0;
	int one_cnt = 0;
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp < 0) { 
			m_arr.push(tmp);
		}
		else if (tmp == 0) {
			zero_cnt++;
		}
		else if (tmp == 1) {
			one_cnt++;
		}
		else { // 2����
			p_arr.push(tmp);
		}
	}
	long long sum = 0;
	// ���� ���
	while (!m_arr.empty()) {
		if (m_arr.size() >= 2) {
			long long a = m_arr.top(); m_arr.pop();
			long long b = m_arr.top(); m_arr.pop();
			sum += a * b;
		}
		else {
			break;
		}
	}
	
	// 0���� ���� ����
	while (!m_arr.empty()) {
		if (zero_cnt == 0) { break; }
		m_arr.pop();
		zero_cnt--;
	}
	// ������ ���� ����
	while (!m_arr.empty()) {
		int n = m_arr.top(); m_arr.pop();
		sum += n;
	}
	// 1 ������ŭ ����
	sum += one_cnt;

	// 2 �̻��� �� ����
	while (!p_arr.empty()) {
		if (p_arr.size() >= 2) {
			long long a = p_arr.top(); p_arr.pop();
			long long b = p_arr.top(); p_arr.pop();
			sum += a * b;
		}
		else {
			long long a = p_arr.top(); p_arr.pop();
			sum += a;
		}
	}
	cout << sum << endl;
}