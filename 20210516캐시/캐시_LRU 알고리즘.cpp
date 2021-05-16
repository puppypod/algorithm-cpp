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
        // �ҹ��� ����
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        // miss
        if (m.find(cities[i]) == m.end()) {
            m[cities[i]] = i;
            answer += 5;
            if (m.size() > cacheSize) {
                map<string, int>::iterator iter;
                map<string, int>::iterator eraseIter;
                string str;
                // ���� ���� ���ڰ� ���� ������ ĳ�� ������
                int minimum = 100001;
                for (iter = m.begin(); iter != m.end(); iter++) {
                    if (minimum > iter->second) { // ���� ������ ĳ�� ������ �̱�
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