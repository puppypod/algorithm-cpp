#include<iostream>
using namespace std;

bool check(string str) {
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i]) { // �Ӹ������ �ƴҶ�
			return false;
		}
	}
	return true; // �� �ݺ����� ��ġ�� ���� �����Ѵٸ� �Ӹ������.
}
int main()
{
	string s;
	cin >> s;

	int idx = 0;
	do {
		if (check(s)) { break; }
		else {
			s.erase(s.size() - idx);
		}
		for (int i = idx; i >= 0; i--) {
			s.push_back(s[i]);
		}
		idx++;
	} while (idx != s.size());
	cout << s.size() << endl;
}