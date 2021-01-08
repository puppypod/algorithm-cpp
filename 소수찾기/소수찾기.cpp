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
    if (cnt == b) { // 조합의 결과, 이후 순열로 만들것임.
        bool isnot = false;
        do { // 순열 만들기, next_permutation을 이용.
            int num = 0;
            // char에서 int로 만들기
            for (int i = 0; i < cnt; i++) {
                num += arr[i] * pow(10, (cnt - i));
            }
            num /= 10;
            // num이 1보다 작으면 소수가 아님, 예외처리
            if (num <= 1) { break; }
            // 소수판별 알고리즘
            for (int i = 2; i <= sqrt(num); i++) { 
                if (num % i == 0) {//나누어떨어지면 소수가 아님
                    isnot = true;
                    break;
                }
            }
            if (!isnot) { // 소수라면 카운트
                cout << num << endl;
                overlapDel.push_back(num);
            } 
            isnot = false;
        } while (next_permutation(arr, arr + cnt)); // 순열을 구해주는 함수
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
    // 오름차순으로  int 형 배열 만들기
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