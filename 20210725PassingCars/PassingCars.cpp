// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A) {
    int plusNum = 0;
    int sum = 0;
    for (int num : A) {
        if (num == 0) {
            plusNum++;
        }
        else {
            sum += plusNum;
            if (sum > 1000000000) return -1;
        }
    }
    return sum;
}