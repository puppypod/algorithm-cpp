#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(), 0);
    vector<vector<string>> infoStr;
    vector<vector<int>> queryIdx(query.size());
    vector<int> db[3][2][2][2];

    // info 분리
    for (int i = 0; i < info.size(); i++) {
        string str = info[i];
        int idx = 0;
        int prev = 0;
        vector<string> v;
        while ((idx = str.find(" ", prev + 1)) != string::npos) {
            v.push_back(str.substr(prev, idx - prev));
            prev = idx + 1;
        }
        v.push_back(str.substr(prev));
        infoStr.push_back(v);
    }
    // query 분리
    for (int i = 0; i < query.size(); i++) {
        string str = query[i];
        int idx = 0;
        int prev = 0;
        vector<string> v;
        while ((idx = str.find(" ", prev + 1)) != string::npos) {
            v.push_back(str.substr(prev, idx - prev));
            prev = idx + 1;
            idx = str.find(" ", prev + 1);
            if (idx == string::npos) { break; }
            prev = idx + 1;
        }
        v.push_back(str.substr(prev));
        for (int j = 0; j < 5; j++) {
            if (j == 0) {
                if (v[j] == "cpp") { queryIdx[i].push_back(0); }
                else if (v[j] == "java") { queryIdx[i].push_back(1); }
                else if (v[j] == "python") { queryIdx[i].push_back(2); }
                else {
                    queryIdx[i].push_back(-1);
                }
            }
            else if (j == 1) {
                if (v[j] == "backend") { queryIdx[i].push_back(0); }
                else if (v[j] == "frontend") { queryIdx[i].push_back(1); }
                else {
                    queryIdx[i].push_back(-1);
                }
            }
            else if (j == 2) {
                if (v[j] == "junior") { queryIdx[i].push_back(0); }
                else if (v[j] == "senior") { queryIdx[i].push_back(1); }
                else {
                    queryIdx[i].push_back(-1);
                }
            }
            else if (j == 3) {
                if (v[j] == "chicken") { queryIdx[i].push_back(0); }
                else if (v[j] == "pizza") { queryIdx[i].push_back(1); }
                else {
                    queryIdx[i].push_back(-1);
                }
            }
            else {
                queryIdx[i].push_back(stoi(v[j]));
            }
        }
    }


    // 데이터 베이스 구축
    for (int i = 0; i < infoStr.size(); i++) {
        vector<int> v;
        for (int j = 0; j < 5; j++) {
            if (j == 0) {
                if (infoStr[i][j] == "cpp") { v.push_back(0); }
                else if (infoStr[i][j] == "java") { v.push_back(1); }
                else if (infoStr[i][j] == "python") { v.push_back(2); }
            }
            else if (j == 1) {
                if (infoStr[i][j] == "backend") { v.push_back(0); }
                else if (infoStr[i][j] == "frontend") { v.push_back(1); }
            }
            else if (j == 2) {
                if (infoStr[i][j] == "junior") { v.push_back(0); }
                else if (infoStr[i][j] == "senior") { v.push_back(1); }
            }
            else if (j == 3) {
                if (infoStr[i][j] == "chicken") { v.push_back(0); }
                else if (infoStr[i][j] == "pizza") { v.push_back(1); }
            }
            else {
                db[v[0]][v[1]][v[2]][v[3]].push_back(stoi(infoStr[i][j]));
            }
        }
    }
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                for (int d = 0; d < 2; d++) {
                    sort(db[a][b][c][d].begin(), db[a][b][c][d].end());
                }
            }
        }
    }

    // 검색 시작
    for (int i = 0; i < queryIdx.size(); i++) {
        vector<int> idx = queryIdx[i];
        vector<int> a;
        vector<int> b;
        vector<int> c;
        vector<int> d;
        // 언어
        if (idx[0] == -1) {
            for (int j = 0; j < 3; j++) {
                a.push_back(j);
            }
        }
        else {
            a.push_back(idx[0]);
        }
        // 직군
        if (idx[1] == -1) {
            for (int j = 0; j < 2; j++) {
                b.push_back(j);
            }
        }
        else {
            b.push_back(idx[1]);
        }
        // 경력
        if (idx[2] == -1) {
            for (int j = 0; j < 2; j++) {
                c.push_back(j);
            }
        }
        else {
            c.push_back(idx[2]);
        }
        // 소울 푸드
        if (idx[3] == -1) {
            for (int j = 0; j < 2; j++) {
                d.push_back(j);
            }
        }
        else {
            d.push_back(idx[3]);
        }

        // 점수
        int score = idx[4];

        for (int aa : a) {
            for (int bb : b) {
                for (int cc : c) {
                    for (int dd : d) {
                        if (!db[aa][bb][cc][dd].empty()) {
                            auto iter = lower_bound(db[aa][bb][cc][dd].begin(), db[aa][bb][cc][dd].end(), score);
                            answer[i] += db[aa][bb][cc][dd].end() - iter;
                        }
                    }
                }
            }
        }
    }

    return answer;
}