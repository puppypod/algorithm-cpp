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
            // ä��â ����
            if (!listOps[uid].empty()) {
                for (int i = 0; i < listOps[uid].size(); i++) {
                    int idx = listOps[uid].at(i); // ������ idx

                    answer[idx].replace(0, nameOps[uid].size(), name);
                }
            }
            // ���ο� ���� ������Ʈ
            nameOps[uid] = name;
            listOps[uid].push_back(listNum);
            answer.push_back(name + "���� ���Խ��ϴ�.");
            listNum++;
        }
        else if (oper == "Leave") {
            answer.push_back(nameOps[uid] + "���� �������ϴ�.");
            listOps[uid].push_back(listNum);
            listNum++;
        }
        else { // change
            // ä��â ����
            for (int i = 0; i < listOps[uid].size(); i++) {
                int idx = listOps[uid].at(i); // ������ idx

                answer[idx].replace(0, nameOps[uid].size(), name);
            }
            nameOps[uid] = name;
        }

    }

    return answer;
}