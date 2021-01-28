#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int a, b, c;
	int inp;
	long long sum = 0;
	vector<int> people;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> inp;
		people.push_back(inp);
	}
	cin >> b >> c;

	for (int i = 0; i < people.size(); i++) {
		if (people[i] - b >= 0) {
			people[i] -= b;
		}
		else {
			people[i] = 0;
		}
		sum++;
	}

	
	for (int i = 0; i < people.size(); i++) {
		if (people[i]) {
			if (people[i] < c) {
				people[i] = 0;
				sum++;
			}
			else {
				sum = sum + (people[i] / c);
				if (people[i] % c) {
					sum++;
				}
			}
		}
	}
	cout << sum << endl;
}