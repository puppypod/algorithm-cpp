#include <iostream>
#include <deque>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string originStr;
	string targetStr;
	cin >> originStr;
	cin >> targetStr;
	deque<char> check;
	set<char> s;
	int strSize = targetStr.size();

	for (int i = 0; i < strSize; i++) {
		s.insert(targetStr[i]);
	}

	string newStr;

	for (int i = 0; i < originStr.size(); i++) {
		if (s.find(originStr[i]) == s.end()) {
			while (!check.empty()) {
				newStr.push_back(check.front());
				check.pop_front();
			}
			newStr.push_back(originStr[i]);
		}
		else {
			check.push_back(originStr[i]);
			if (check.size() >= strSize) {
				int lastIdx = check.size() - 1;
				bool isSame = true;
				for (int j = strSize - 1; j >= 0; j--) {
					if (check[lastIdx--] != targetStr[j]) {
						isSame = false;
						break;
					}
				}
				if (isSame) {
					for (int j = 0; j < strSize; j++) {
						check.pop_back();
					}
				}
			}
		}
	}
	while (!check.empty()) {
		newStr.push_back(check.front());
		check.pop_front();
	}

	if (!newStr.empty()) {
		cout << newStr;
	}
	else {
		cout << "FRULA";
	}
}