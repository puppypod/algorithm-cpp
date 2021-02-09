#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<int> v;
    int num = 0;
    char change;
    int tmp;
    int circle_num = 1; // 초기 순서 초기화
    int myTurn = (p-1) % m + 1;
    int size;
    while (answer.size() != t) {
        // 진수에 알맞는 수를 알려주는  알고리즘 작성
        tmp = num;
        v.push_back(tmp % n);
        while ((tmp / n) != 0) {
            tmp /= n;
            v.push_back(tmp % n);
        }
        size = v.size();
        for (int i = 0; i < size; i++) {
            if (myTurn == (circle_num-1)%m + 1) {
                if (v.back() < 10) {
                    change = v.back() + 48;
                }
                else {
                    change = v.back() + 55;
                }
                answer.push_back(change);
                if (answer.size() == t) { break; }
            }
            circle_num++;
            v.pop_back();
            
        }

        num++;
    }

    return answer;
}
int main()
{
    cout << solution(2, 4, 2, 1) << endl;
}