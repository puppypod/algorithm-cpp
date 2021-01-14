#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(vector<int> people, int limit) {
    int answer = 0;
    int mid = limit / 2;
    vector<int> left;
    vector<int> right;

    sort(people.begin(), people.end());
    for (int i = 0; i < people.size(); i++) {
        if (people[i] <= mid) { left.push_back(people[i]); }
        else { right.push_back(people[i]); }
    }
    //left와 right를 더해주되, left에서 가장 큰값 + right에서 가장 작은값 순서로
    //right가 전부 비어있으면 (left 개수 / 2)을 더해주면 됨<나머지가 1이면 +1>
    //right가 비어있지 않으면 남은 개수만큼 더해주면 됨.
    int a = 0;
    for (int i = left.size() - 1; i >= 0; i--) {
        for (int j = a; j < right.size(); j++) {
            if (left[i] + right[j] > limit) {
                if (j == 0) { break; }
                else {
                    left.erase(left.begin() + i);
                    right.erase(right.begin() + j - 1);
                    answer++;
                    a = j - 1;
                    break;
                }
            }
            else {
                if (right.size() - 1 == j) {
                    left.erase(left.begin() + i);
                    right.erase(right.begin() + j);
                    answer++;
                    a = right.size() - 1;
                    break;
                }
            }
        }
    }
    if (left.size() % 2) { answer += left.size() / 2 + 1; }
    else { answer += left.size() / 2; }
    answer += right.size();

    return answer;
}
int main()
{
    cout << solution({ 70, 50, 80, 50,30,20 }, 100);
}