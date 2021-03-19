#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>

#define endl "\n"
#define MAX 20
using namespace std;

typedef struct
{
    int x;
    int y;
    int Size;
    int Eat_Num;
    int Time;
}Shark;

typedef struct
{
    int x;
    int y;
    int Dist;
}Food;

int N;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];

Shark S;
vector<Food> V;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1 ,-1 ,0 ,0 };

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 9)
            {
                S.x = i;
                S.y = j;
                S.Size = 2;
                S.Eat_Num = 0;
                S.Time = 0;
            }
        }
    }
}

void BFS(int a, int b)
{
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(a, b), 0));
    Visit[a][b] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Dist = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (Visit[nx][ny] == false)
                {
                    if (MAP[nx][ny] == 0)
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), Dist + 1));
                    }
                    else if (MAP[nx][ny] < S.Size)
                    {
                        Food Temp;
                        Temp.x = nx;
                        Temp.y = ny;
                        Temp.Dist = Dist + 1;

                        V.push_back(Temp);
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), Dist + 1));
                    }
                    else if (MAP[nx][ny] == S.Size)
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), Dist + 1));
                    }
                }
            }
        }
    }
}

bool Sorting_Standard(Food A, Food B)
{
    if (A.Dist <= B.Dist)
    {
        if (A.Dist == B.Dist)
        {
            if (A.x <= B.x)
            {
                if (A.x == B.x)
                {
                    if (A.y < B.y)
                    {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void Solution()
{
    while (1)
    {
        V.clear();
        memset(Visit, false, sizeof(Visit));

        BFS(S.x, S.y);
        if (V.size() == 0)
        {
            cout << S.Time << endl;
            break;
        }
        else if (V.size() == 1)
        {
            MAP[V[0].x][V[0].y] = 9;
            MAP[S.x][S.y] = 0;
            S.x = V[0].x;
            S.y = V[0].y;
            S.Eat_Num++;
            S.Time = S.Time + V[0].Dist;

            if (S.Eat_Num == S.Size)
            {
                S.Eat_Num = 0;
                S.Size++;
            }
        }
        else
        {
            sort(V.begin(), V.end(), Sorting_Standard);
            MAP[V[0].x][V[0].y] = 9;
            MAP[S.x][S.y] = 0;
            S.x = V[0].x;
            S.y = V[0].y;
            S.Eat_Num++;
            S.Time = S.Time + V[0].Dist;

            if (S.Eat_Num == S.Size)
            {
                S.Eat_Num = 0;
                S.Size++;
            }
        }
    }
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}