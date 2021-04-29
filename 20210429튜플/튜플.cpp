#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(string s) {
    bool Visit[100010] = { false, };
    vector<int> answer;
    vector<string> V[510];
    int Idx = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            string Temp = "";
            int j = i + 1;
            while (1)
            {
                if (s[j] == '}') break;
                if (s[j] == ',')
                {
                    V[Idx].push_back(Temp);
                    Temp = "";
                    j++;
                    continue;
                }
                Temp = Temp + s[j];
                j++;
            }
            V[Idx++].push_back(Temp);
        }
    }
    int Len = 1;
    while (1)
    {
        bool Flag = false;
        for (int i = 0; i < Idx; i++)
        {
            if (V[i].size() == Len)
            {
                Flag = true;
                for (int j = 0; j < V[i].size(); j++)
                {
                    int Num = stoi(V[i][j]);
                    if (Visit[Num] == false)
                    {
                        Visit[Num] = true;
                        answer.push_back(Num);
                    }
                }
                Len++;
                break;
            }
        }
        if (Flag == false) break;
    }

    return answer;
}