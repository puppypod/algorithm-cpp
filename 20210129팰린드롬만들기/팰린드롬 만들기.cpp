#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string name;
	string result;
	int keep_idx = -1; // -1�̸� ¦���� �� �̻��̸� Ȧ����
	char keep_alpha;
	cin >> name;

	sort(name.begin(), name.end());
	if (name.size() % 2) { // name�� ���̰� Ȧ�����
		int check = 0;
		for (int i = 0; i < name.size(); i += 2) {
			if (i == name.size() - 1) {
				keep_idx = i;
				check++;
				if (check == 2) { // Ȧ�� ������ ���ĺ��� 1�������� ���Ǳ� ������
					cout << "I'm Sorry Hansoo" << endl;
					return 0;
				}
			}
			else if(name[i] != name[i + 1]) {
				keep_idx = i;
				check++;
				i--;
				if (check == 2) { // Ȧ�� ������ ���ĺ��� 1�������� ���Ǳ� ������
					cout << "I'm Sorry Hansoo" << endl;
					return 0;
				}
			}
		}
		keep_alpha = name[keep_idx];
		name.erase(keep_idx, 1);
	}
	else { // name�� ���̰� ¦�����
		for (int i = 0; i < name.size(); i+=2) {
			if (name[i] != name[i + 1]) {
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
		}
	}
	// �˰��� ����
	for (int i = 0; i < name.size(); i += 2) {
		result.push_back(name[i]);
	}
	
	for (int i = result.size()-1; i >= 0; i--) {
		result.push_back(result[i]);
	}

	if (keep_idx != -1) { // Ȧ������ �ǹ�
		result.insert(result.begin() + result.size() / 2, keep_alpha);
	}
	cout << result << endl;

	return 0;
}