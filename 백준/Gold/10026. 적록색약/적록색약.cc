#include<iostream>
#include<cstring>
#include<queue>
 
#define endl "\n"
#define MAX 100
using namespace std;
 
int N;
char MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
void BFS(int a, int b)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Visit[a][b] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (Visit[nx][ny] == false)
                {
                    if (MAP[nx][ny] == MAP[x][y])
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}
void Solution()
{
    int Answer, Answer2;
    Answer = Answer2 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Visit[i][j] == false)
            {
                BFS(i, j);
                Answer++;
            }
        }
    }
 
    memset(Visit, false, sizeof(Visit));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j] == 'G') MAP[i][j] = 'R';
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Visit[i][j] == false)
            {
                BFS(i, j);
                Answer2++;
            }
        }
    }
 
    cout << Answer << " " << Answer2 << endl;
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
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
