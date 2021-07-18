#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int>& A) {
    int sum = 0;
    for (int num : A) {
        sum += num;
    }
    int answer = 100000001;
    int startSum = 0;
    for (int i = 0; i < A.size() - 1; i++) {
        startSum += A[i];
        int rightNum = sum - startSum;
        answer = min(answer, abs(rightNum - startSum));
    }
    return answer;
}