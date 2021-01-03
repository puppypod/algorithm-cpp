#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    if (n == 1) { answer.push_back(1); return answer; }
    vector<vector<int>> levelArr(n,vector<int>(n));
    int startNum = 1; // 삼각형을 그릴 때 시작(행)숫자
    int endNum; // 삼각형을 그릴 때 끝(행)숫자
    int finishNum = n * (n + 1) / 2; // 반복문이 종료되는 숫자 flag
    int cnt = 1; // 증가연산할 숫자
    int insertRoom = 0; // 삼각형을 만들어 나갈 때 삽입할 방 번호(열)
    int j; // 삼각형 우측 끝 방번호(열)

    // 풀이 방법 -> 삼각형을 그려나가며 반복문 실행
    while (1) {
        endNum = n;

        for (int i = startNum - 1; i < endNum; i++) { // 삼각형 좌측변, 아랫변 숫자 채우기
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
        for (int i = endNum - 2; i >= startNum; i--) { // 삼각형 우측변 채우기
            levelArr[i][j] = cnt;
            j--;
            cnt++;
        }

        // 삼각형 속의 삼각형 모양으로 숫자 채우기 위해 숫자를 줄임
        n--;
        startNum += 2;
        insertRoom++;
        if (finishNum == cnt - 1) { break; } // 종료조건
    }

    // 결과값을 리턴하기 위해 levelArr값을 answer에 push 해줌
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
