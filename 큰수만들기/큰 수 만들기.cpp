#include <string>
#include <vector>
#include <iostream>
using namespace std;


string solution(string number, int k) {
    string answer = "";
    char cmp = '9';
    bool isFind;
    int startRoom = 0; // 점검할 시작 방번호
    int i;
    int cnt;
    int cnt2 = 0;
    int a = number.size() - k;
    for (i = 0; i < number.size(); i++) {
        if (number[i] != '9') {
            break;
        }
    }
    
    while (1) {
        isFind = false;
        cnt = -1;
        for (i = startRoom; i <= k + startRoom; i++) {
            cnt++; // 몇개를 버릴 수 있을지 결정해줌.
            if (number[i] == cmp) {
                isFind = true;
                break;
            }
        }

        if (isFind) {
            k -= cnt;
            if (k != 0) {
                answer += number[cnt + startRoom];
                if (answer.size() == a) { break; }
                number = number.substr(cnt + startRoom, number.size());;
            }
            else {
                answer += number.substr(cnt + startRoom, number.size());
            }
             // cnt만큼 숫자를 버림
            startRoom=1; // 숫자가 결정되면 startRoom은 1이 되어야함
            
            cmp = '9';
        }
        else {
            cmp -= 1;
        }
        if (k == 0) { break; }
    }

    return answer;
}
int main()
{
    cout << solution("9999", 2) << endl;
}