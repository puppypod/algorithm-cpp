#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

vector<int> candidate;
vector<int> tmp;
vector<vector<string>> R;
vector<vector<int>> vSort;
int N;
int M;


void combination(int a, int b, int K) {
    if (b == K) {
        set<vector<string>> sTmp;
        bool isTrue = true;
        for (int i = 0; i < N; i++) {
            vector<string> v;
            for (int j : tmp) {
                v.push_back(R[i][j]);
            }
            if (sTmp.find(v) != sTmp.end()) {
                isTrue = false;
                break;
            }
            else {
                sTmp.insert(v);
            }
        }

        if (isTrue) {
            vSort.push_back(tmp);
        }

        return;
    }

    for (int i = a; i < M; i++) {
        tmp[b] = candidate[i];
        combination(i + 1, b + 1, K);
    }
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> primaryKey;
    N = relation.size();
    M = relation[0].size();

    for (int i = 0; i < M; i++) {
        candidate.push_back(i);
    }
    R = relation;
    for (int i = 1; i <= M; i++) {
        vector<int> init(i);
        tmp = init;
        combination(0, 0, i);
    }

    // 최소성을 유지하는 후보키 고르기, 여기에 범위를 벗어나는 case가 있음.
    int idx = 0;
    while (idx < vSort.size()) {
        vector<int> a = vSort[idx];
        vector<int> eraseIdx;
        int limit = a.size();
        for (int i = idx + 1; i < vSort.size(); i++) {
            vector<int> b = vSort[i];
            int cnt = 0;
            for (int j = 0; j < a.size(); j++) {
                int aNum = a[j];
                if (find(b.begin(), b.end(), aNum) != b.end()) {
                    cnt++;
                }
            }
            // 최소성을 유지하지 못한 인덱스 저장
            if (cnt == limit) {
                eraseIdx.push_back(i);
            }
        }

        for (int i = eraseIdx.size()-1; i >= 0; i--) {
            vSort.erase(vSort.begin() + eraseIdx[i]);
        }

        idx++;
    }

    answer += vSort.size();


    return answer;
}