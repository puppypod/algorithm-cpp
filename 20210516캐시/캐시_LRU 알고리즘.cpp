#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    map<string, int> m;
    
    for (int i = 0; i < cities.size(); i++) {
        // 소문자 통합
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        // miss
        if (m.find(cities[i]) == m.end()) {
            m[cities[i]] = i;
            answer += 5;
            if (m.size() > cacheSize) {
                map<string, int>::iterator iter;
                map<string, int>::iterator eraseIter;
                string str;
                // 가장 작은 숫자가 가장 오래된 캐시 데이터
                int minimum = 100001;
                for (iter = m.begin(); iter != m.end(); iter++) {
                    if (minimum > iter->second) { // 가장 오래된 캐시 데이터 뽑기
                        minimum = iter->second;
                        eraseIter = iter;
                    }
                }
                m.erase(eraseIter);
            }
        }
        // hit
        else {
            m[cities[i]] = i;
            answer += 1;
        }
    }


    return answer;
}