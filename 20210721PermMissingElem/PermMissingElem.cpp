#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& A) {
	vector<int> arr(A.size() + 2, 0);
	for (int num : A) {
		arr[num] = 1;
	}

	for (int i = 1; i <= A.size() + 1; i++) {
		if (!arr[i]) {
			return i;
		}
	}
	return 0;
}