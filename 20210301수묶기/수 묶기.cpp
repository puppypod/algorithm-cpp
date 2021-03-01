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
		else { // 2ºÎÅÍ
			p_arr.push(tmp);
		}
	}
	long long sum = 0;
	// À½¼ö °è»ê
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
	
	// 0À¸·Î À½¼ö Á¦°Å
	while (!m_arr.empty()) {
		if (zero_cnt == 0) { break; }
		m_arr.pop();
		zero_cnt--;
	}
	// ³ª¸ÓÁö À½¼ö µ¡¼À
	while (!m_arr.empty()) {
		int n = m_arr.top(); m_arr.pop();
		sum += n;
	}
	// 1 °³¼ö¸¸Å­ µ¡¼À
	sum += one_cnt;

	// 2 ÀÌ»óÀÇ ¼ö µ¡¼À
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