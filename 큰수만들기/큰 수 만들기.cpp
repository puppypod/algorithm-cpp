#include <string>
#include <vector>
#include <iostream>
using namespace std;


string solution(string number, int k) {
    string answer = "";
    char cmp = '9';
    bool isFind;
    int startRoom = 0; // ������ ���� ���ȣ
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
            cnt++; // ��� ���� �� ������ ��������.
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
             // cnt��ŭ ���ڸ� ����
            startRoom=1; // ���ڰ� �����Ǹ� startRoom�� 1�� �Ǿ����
            
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