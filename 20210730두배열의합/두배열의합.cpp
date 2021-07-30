#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<long long> APointer;
vector<long long> BPointer;

bool cmp(const long long a, const long long b) {
	return a > b;
}
vector<long long> SUM(const vector<long long>& v) {
	vector<long long> tmp;
	for (int i = 0; i < v.size(); i++) {
		long long sum = 0;
		for (int j = i; j < v.size(); j++) {
			sum += v[j];
			tmp.push_back(sum);
		}
	}
	return tmp;
}
int main()
{
	long long T;
	int n;
	cin >> T >> n;

	vector<long long> A;
	vector<long long> B;

	for (int i = 0; i < n; i++) {
		long long tmp; cin >> tmp;
		A.push_back(tmp);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long tmp; cin >> tmp;
		B.push_back(tmp);
	}
	APointer = SUM(A);
	BPointer = SUM(B);
	
	
	sort(APointer.begin(), APointer.end());
	sort(BPointer.begin(), BPointer.end(), cmp);

	long long sum = 0;
	int ap = 0;
	int bp = 0;
	long long answer = 0;
	while (bp < BPointer.size() && ap < APointer.size()) {
		long long aNum = APointer[ap];
		long long target = T - aNum;
		
		if (BPointer[bp] > target) {
			bp++;
		}
		else if (BPointer[bp] == target) {
			long long acnt = 0;
			long long bcnt = 0;
			while (ap < APointer.size() && APointer[ap] == aNum) {
				acnt++;
				ap++;
			} 
			while (bp < BPointer.size() && BPointer[bp] == target) {
				bcnt++;
				bp++;
			}
			answer += acnt * bcnt;
		}
		else {
			ap++;
		}

	}

	cout << answer;
}