#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;

int n;
int arr[7];
int answer[7];
vector<int> overlapDel;

void dfs(int a, int b, int cnt) {
    if (cnt == b) { // ������ ���, ���� ������ �������.
        bool isnot = false;
        do { // ���� �����, next_permutation�� �̿�.
            int num = 0;
            // char���� int�� �����
            for (int i = 0; i < cnt; i++) {
                num += arr[i] * pow(10, (cnt - i));
            }
            num /= 10;
            // num�� 1���� ������ �Ҽ��� �ƴ�, ����ó��
            if (num <= 1) { break; }
            // �Ҽ��Ǻ� �˰���
            for (int i = 2; i <= sqrt(num); i++) { 
                if (num % i == 0) {//����������� �Ҽ��� �ƴ�
                    isnot = true;
                    break;
                }
            }
            if (!isnot) { // �Ҽ���� ī��Ʈ
                cout << num << endl;
                overlapDel.push_back(num);
            } 
            isnot = false;
        } while (next_permutation(arr, arr + cnt)); // ������ �����ִ� �Լ�
        return;
    }
    for (int i = a; i < n; i++) {
        arr[b] = answer[i];
        dfs(i + 1, b + 1, cnt);
    }
}
int solution(string numbers) {
    
    char num[7];
    int len = numbers.size();
    n = len;
    // ������������  int �� �迭 �����
    strcpy(num, numbers.c_str());
    sort(num, num + len);
    for (int i = 0; i < len; i++) {
        answer[i] = num[i] - 48;
    }
    for (int i = 1; i <= len; i++) {
        dfs(0, 0, i);
    }
    sort(overlapDel.begin(), overlapDel.end());
    overlapDel.erase(unique(overlapDel.begin(), overlapDel.end()), overlapDel.end());


    return overlapDel.size();
}
int main()
{
    cout << solution("123") << endl;
}