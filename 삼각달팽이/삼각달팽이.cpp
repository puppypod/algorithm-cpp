#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    if (n == 1) { answer.push_back(1); return answer; }
    vector<vector<int>> levelArr(n,vector<int>(n));
    int startNum = 1; // �ﰢ���� �׸� �� ����(��)����
    int endNum; // �ﰢ���� �׸� �� ��(��)����
    int finishNum = n * (n + 1) / 2; // �ݺ����� ����Ǵ� ���� flag
    int cnt = 1; // ���������� ����
    int insertRoom = 0; // �ﰢ���� ����� ���� �� ������ �� ��ȣ(��)
    int j; // �ﰢ�� ���� �� ���ȣ(��)

    // Ǯ�� ��� -> �ﰢ���� �׷������� �ݺ��� ����
    while (1) {
        endNum = n;

        for (int i = startNum - 1; i < endNum; i++) { // �ﰢ�� ������, �Ʒ��� ���� ä���
            levelArr[i][insertRoom] = cnt;
            if (i == endNum - 1) {
                for (j = insertRoom+1; j < endNum; j++) {
                    if (levelArr[i][j] == 0) {
                        cnt++;
                        levelArr[i][j] = cnt;
                    }
                    else {
                        break;
                    }
                }
            }
            cnt++;
        }

        j -= 2;
        for (int i = endNum - 2; i >= startNum; i--) { // �ﰢ�� ������ ä���
            levelArr[i][j] = cnt;
            j--;
            cnt++;
        }

        // �ﰢ�� ���� �ﰢ�� ������� ���� ä��� ���� ���ڸ� ����
        n--;
        startNum += 2;
        insertRoom++;
        if (finishNum == cnt - 1) { break; } // ��������
    }

    // ������� �����ϱ� ���� levelArr���� answer�� push ����
    cnt = 1;
    for (int i = 0; i < levelArr.size(); i++) {
        for (int j = 0; j < cnt; j++) {
            answer.push_back(levelArr[i][j]);
        }
        cnt++;
    }



    return answer;
}
int main()
{
    int n;
    
    cin >> n;
    vector<int> answer(solution(n));
    vector<int>::iterator iter;
    for (iter = answer.begin(); iter != answer.end() ; iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}
