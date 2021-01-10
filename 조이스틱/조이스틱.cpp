#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int moveAlphabet(string name) {
    int mn = name.size() - 1;
    int cnt = 0;
    int left, right;
    for (int i = name.size() - 1; i >= 1; i--) { // ���������� �̵����� �� ���õǴ� ���ĺ�
        if (name[i] == 'A') {
            cnt++;
            continue;
        }
        break;
    }
    mn -= cnt;
    cnt = 0;
    for (int i = 1; i < name.size() - 1; i++) {
        if (name[i] == 'A') {
            cnt++;
            continue;
        }
        break;
    }
    mn = (mn < name.size() - 1 - cnt) ? mn : name.size() - 1 - cnt;

    if (name[name.size() / 2] == 'A') {
        left = name.size() / 2 - 1;
        right = name.size() - left - 2;
        for (int i = name.size() / 2 - 1; i >= 1; i--) {
            if (name[i] == 'A') {
                left--;
                continue;
            }
            break;
        }

        for (int i = name.size() / 2 + 1; i < name.size(); i++) {
            if (name[i] == 'A') {
                right--;
                continue;
            }
            break;
        }
        mn = (mn < left * 2 + right) ? mn : left * 2 + right;
        mn = (mn < right * 2 + left) ? mn : right * 2 + left;
    }

    return mn;
}
int checkConv(string name) {
    int sum = 0;
    for (int i = 0; i < name.size(); i++) {
        if (name[i] <= 'N') { // ���������� ���ĺ��� �ٲ��� ��
            sum += name[i] - 65;
        }
        else { // ������ ���ĺ��� �ٲ��� ��
            sum += abs(name[i] - 91);
        }
    }
    return sum;
}
int solution(string name) {
    int convSum;
    int moveSum;
    int mn = 21;
    int aCnt = 0;

    convSum = checkConv(name);
    moveSum = moveAlphabet(name);

    return convSum + moveSum;
}
int main()
{
    cout << solution("BBCDE") << endl;
}