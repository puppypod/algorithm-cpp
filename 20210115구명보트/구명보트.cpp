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
    //left�� right�� �����ֵ�, left���� ���� ū�� + right���� ���� ������ ������
    //right�� ���� ��������� (left ���� / 2)�� �����ָ� ��<�������� 1�̸� +1>
    //right�� ������� ������ ���� ������ŭ �����ָ� ��.
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