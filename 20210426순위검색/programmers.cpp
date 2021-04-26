#include <string>
#include <vector>
#include <iostream> // sscanf() ���
#include <string.h> // strcmp() ���
#include <algorithm> // sort() ���

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    ios_base::sync_with_stdio(0);
    sort(info.begin(), info.end());

    vector<int> answer(query.size(), 0);
    int count = 0;

    for (string q : query) {
        const char* ch;
        char q_info[4][10];
        ch = q.c_str();

        int score;
        sscanf(ch, "%7s and %9s and %7s and %8s %d", q_info[0], q_info[1], q_info[2], q_info[3], &score);

        for (string tmp : info) {
            const char* applyer_info;
            char a_info[4][10];
            applyer_info = tmp.c_str();

            int applyer_score;
            sscanf(applyer_info, "%7s %9s %7s %8s %d", a_info[0], a_info[1], a_info[2], a_info[3], &applyer_score);


            bool isTrue = true;
            for (int i = 0; i < 4; i++) {
                if (strcmp(q_info[i], a_info[i])) { // �ٸ��ٸ�
                    if (!strncmp(q_info[i], "-", 1)) {
                        continue;
                    }
                    isTrue = false;
                    break;
                }
            }
            if (isTrue) { // ���ٸ� ���� ������ ���ϸ� ��.
                if (applyer_score >= score) { // ���� ���� �̻��̶��
                    answer[count]++;
                }
            }
        }
        count++;
    }

    return answer;
}