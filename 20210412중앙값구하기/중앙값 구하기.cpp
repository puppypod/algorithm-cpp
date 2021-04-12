#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int testCase;
	cin >> testCase;
	while (testCase--) {

		int candidateNum;
		vector<int> v;
		vector<int> tmp;
		cin >> candidateNum;
		for (int i = 0; i < candidateNum; i++) {
			int num;
			cin >> num;
			v.push_back(num);
			if (i % 2 == 0) {
				sort(v.begin(), v.end());
				tmp.push_back(v[i / 2]);
			}
		}
		cout << tmp.size() << endl;
		for (int i = 0; i < tmp.size(); i++) {
			cout << tmp[i] << " ";
		}
		cout << endl;
	}
}