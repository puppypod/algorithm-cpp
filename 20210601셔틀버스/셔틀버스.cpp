#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

string answer = "";
priority_queue<int, vector<int>, greater<int>> pq;

void conversion(int time) {
    if (time / 60 >= 10) {
        answer += to_string(time / 60);
        answer += ":";
        if (time % 60 >= 10) {
            answer += to_string(time % 60);
        }
        else {
            answer += "0";
            answer += to_string(time % 60);
        }
    }
    else {
        answer += "0";
        answer += to_string(time / 60);
        answer += ":";
        if (time % 60 >= 10) {
            answer += to_string(time % 60);
        }
        else {
            answer += "0";
            answer += to_string(time % 60);
        }
    }
}
string solution(int n, int t, int m, vector<string> timetable) {
    
    vector<int> bus;
    
    for (int i = 0; i < n; i++) {
        bus.push_back(9 * 60 + t * i);
    }
    for (int i = 0; i < timetable.size(); i++) {
        string str = timetable[i];
        char ch[10];
        int a, b;
        strcpy(ch, str.c_str());
        int tmp = sscanf(ch, "%2d:%2d", &a, &b);
        pq.push(a * 60 + b);
    }

    for (int i = 0; i < bus.size(); i++) {
        int time = bus[i];
        int limitNum = m;

        if (i == bus.size() - 1) { // 마지막 버스일 때
            if (pq.size() < m) { // 남아있는 사람 숫자 < 버스최대허용인원
                conversion(time);
            }
            else { // 
                int lastPerson = pq.top();
                while (!pq.empty() && pq.top() <= time && limitNum--) {
                    lastPerson = pq.top();
                    pq.pop();
                }
                // 버스가 꽉차지 않았으면
                if (limitNum >= 1) {
                    conversion(time);
                }
                else { // 버스가 꽉찼다면 마지막에 탑습한 사람보다 1분 빨라야함.
                    time = lastPerson - 1;
                    conversion(time);
                }
            }
        }
        // 마지막 버스가 아니라면 사람들 태우기
        else {
            while (!pq.empty() && pq.top() <= time && limitNum--) {
                pq.pop();
            }
        }
    }

    return answer;
}