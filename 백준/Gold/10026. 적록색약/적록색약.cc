#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int n;
char board[101][101];
bool check[101][101];
int red = 0;
int blue = 0;
int green = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int res = 0; // 적록색맹 아닌 사람
int resX = 0; // 적록색맹인 사람

void BFS(int x, int y)
{
    cout << "BFS 시작 :" << "{" << x << ", " << y << "}\n";
    queue<pair<int, int>> que;
    check[x][y] = true;

    que.push({x, y});

    while(!que.empty())
    {
        int first = que.front().first;
        int second = que.front().second;
        que.pop();

        for(int dir=0; dir<4; dir++)
        {
            int nx = first + dx[dir];
            int ny = second + dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            else
            {
                if(!check[nx][ny])
                {
                    if(board[nx][ny]==board[x][y])
                    {
                        check[nx][ny] = true;
                        que.push({nx, ny});
                    }
                }
            }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    string s;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        for(int j=0; j<n; j++)
        {
            board[i][j] = (char) s[j];
        }
    }

    cout << "적록색맹 아닌 사람꺼\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!check[i][j])
            {
                BFS(i, j);
                res++;
            }
        }
    }

    memset(check, false, sizeof(check)); // 방문 배열 초기화
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j]=='R')
                board[i][j] = 'G'; // 빨간색 초록색으로 바꾸기

            /*if(!check[i][j])
            {
                BFS(i, j);
                resX++;
            }*/
        }
    }
    
    cout << "적록색맹인 사람꺼\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!check[i][j])
            {
                BFS(i, j);
                resX++;
            }
        }
    }

    cout << res << " " << resX;
    return 0;
}
