#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> nameOps;
    map<string, vector<int>> listOps;

    int listNum = 0;
    for (string str : record) {
        unsigned int n = str.find(" ");
        string oper = str.substr(0, n);
        string uid;
        string name;
        if (oper != "Leave") {
            unsigned int n1 = str.find(" ", n + 1);
            uid = str.substr(n + 1, n1 - n - 1);

            name = str.substr(n1 + 1);
        }
        else {
            uid = str.substr(n + 1);
        }


        if (oper == "Enter") {
            // 채팅창 수정
            if (!listOps[uid].empty()) {
                for (int i = 0; i < listOps[uid].size(); i++) {
                    int idx = listOps[uid].at(i); // 수정할 idx

                    answer[idx].replace(0, nameOps[uid].size(), name);
                }
            }
            // 새로운 정보 업데이트
            nameOps[uid] = name;
            listOps[uid].push_back(listNum);
            answer.push_back(name + "님이 들어왔습니다.");
            listNum++;
        }
        else if (oper == "Leave") {
            answer.push_back(nameOps[uid] + "님이 나갔습니다.");
            listOps[uid].push_back(listNum);
            listNum++;
        }
        else { // change
            // 채팅창 수정
            for (int i = 0; i < listOps[uid].size(); i++) {
                int idx = listOps[uid].at(i); // 수정할 idx

                answer[idx].replace(0, nameOps[uid].size(), name);
            }
            nameOps[uid] = name;
        }

    }

    return answer;
}