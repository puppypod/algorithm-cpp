#include <string>
#include <vector>

using namespace std;

vector<int> cpy;
int answer = 0;
int limitIdx;

void combinationTarget(const int& target, int sum, int idx) {
    if (idx + 1 == limitIdx) {
        if (sum == target) answer++;
        return;
    }

    combinationTarget(target, sum + cpy[idx + 1], idx + 1);

    combinationTarget(target, sum - cpy[idx + 1], idx + 1);

    return;
}
int solution(vector<int> numbers, int target) {

    limitIdx = numbers.size();
    cpy = numbers;
    combinationTarget(target, 0, -1);

    return answer;
}