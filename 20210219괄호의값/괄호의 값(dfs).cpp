#include <iostream>
#include <vector>
using namespace std;

string str;
int two_num = 0;
int three_num = 0;
vector<int> arr;
vector<int> visit(30, 0);
int check = 0;
int answer;
int tmp;
int solution(int idx, int sum) {
	for (int i = idx; i < str.size(); i++) {
		if (!visit[i]) {
			visit[i] = 1;
			if (str[i] == '(') {
				two_num += 2;
				tmp = solution(i + 1, 0);
				sum += 2 * tmp;
			}
			else if (str[i] == '[') {
				three_num += 3;
				tmp = solution(i + 1, 0);
				sum += 3 * tmp;
			}
			else {
				if (arr[i] == -2) {
					two_num -= 2;
					if (sum == 0) { sum = 1; }
					return sum;
				}
				else {
					three_num -= 3;
					if (sum == 0) { sum = 1; }
					return sum;
				}
			}
		}
	}
	return sum;
}
int main()
{
	vector<char> v;
	cin >> str;
	arr.resize(str.size());
	// 에러 처리
	if (str.size() % 2) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {
		if (v.size() >= 1) {
			if (v.back() == '(' && str[i] == ')') {
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
			arr[i] = 2;
			two_num += arr[i];
		}
		else if (str[i] == ')') {
			arr[i] = -2;
			two_num += arr[i];
		}
		else if (str[i] == '[') {
			arr[i] = 3;
			three_num += arr[i];
		}
		else if (str[i] == ']') {
			arr[i] = -3;
			three_num += arr[i];
		}
		if (two_num < 0 || three_num < 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	if (v.size() != 0) {
		cout << 0 << endl;
	}
	else {
		// 정상적인 입력이 들어왔다면
		cout << solution(0, 0) << endl;
	}
}