#include <iostream>
#include <vector>
using namespace std;
// 2*(2+4*3) -> (�й��Ģ) -> 2*2 + 2*4*3 = 28
// ��, ��ȣ�� ������ ���� ����ϴ� ���� �ƴ�, �й��Ģ�� ���� 
int main()
{
	string str;
	vector<char> v;
	int tmp = 1;
	int answer = 0;
	bool isFirst = true;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (v.size() >= 1) {
			if (v.back()=='(' && str[i] == ')') {
				v.pop_back();
			}
			else if (v.back() == '[' && str[i] == ']') {
				v.pop_back();
			}
			else {
				v.push_back(str[i]);
			}
		}
		else {
			v.push_back(str[i]);
		}
		
		if (str[i] == '(') {
			isFirst = true;
			tmp *= 2;
		}
		else if (str[i] == '[') {
			isFirst = true;
			tmp *= 3;
		}
		else if (str[i] == ')') {
			if (isFirst) {
				answer += tmp;
			}
			tmp /= 2;
			isFirst = false;
		}
		else if (str[i] == ']') {
			if (isFirst) {
				answer += tmp;
			}
			tmp /= 3;
			isFirst = false;
		}
	}
	if (v.size() != 0) {
		cout << 0 << endl;
	}
	else {
		cout << answer << endl;
	}
}