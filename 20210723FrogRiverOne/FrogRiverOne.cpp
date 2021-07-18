#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(int X, vector<int>& A) {
	set<int> s;
	int answer = 0;
	for (int num : A) {
		
		if (s.find(num) == s.end()) {
			s.insert(num);
		}

		if (s.size() == X) return answer;
		answer++;
	}
	return -1;
}